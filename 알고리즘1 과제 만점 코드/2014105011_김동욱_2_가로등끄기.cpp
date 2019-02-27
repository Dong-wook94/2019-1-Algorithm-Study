#include <stdio.h>
#include <stdlib.h>
#define INFI 1000000000
int num_element;
int start_number;
int diagonal;
int *D;
int *W;
long int **EEL;
long int **EER;
int **DDL;
int **DDR;
int **PPL;
int **PPR;
void matrix_set(FILE *f);
void min_energy(int s_number,int L, int R);
int findminimum_L(int L,int R);
int findminimum_R(int L,int R);
void print_output(FILE *f,int L, int R);
void print_path(FILE *f, int L, int R, int last);
void m_free();
int main(void) {
	FILE *f_in;
	FILE *f_out;
	char input_n[100];
	errno_t err_in;
	errno_t err_out;

	printf("input file name?");
	gets_s(input_n,sizeof(input_n));
	err_in = fopen_s(&f_in,input_n,"r");
	matrix_set(f_in);

	min_energy(start_number,0,num_element);
	fclose(f_in);
	
	err_out = fopen_s(&f_out, "output.txt", "w");
	print_output(f_out,1,num_element);
	fclose(f_out);
	m_free();
	return 0;
}
void matrix_set(FILE *f) {
	int i, j;
	fscanf_s(f, "%d", &num_element);
	fscanf_s(f, "%d", &start_number);
	D = (int*)malloc(sizeof(int)*(num_element+1));
	W = (int*)malloc(sizeof(int)*(num_element + 1));
	EEL = (long int **)malloc(sizeof(long int*)*(num_element + 1));
	EER = (long int **)malloc(sizeof(long int*)*(num_element + 1));
	DDL = (int **)malloc(sizeof(int*)*(num_element + 1));
	DDR = (int **)malloc(sizeof(int*)*(num_element + 1));
	PPL = (int **)malloc(sizeof(int*)*(num_element + 1));
	PPR = (int **)malloc(sizeof(int*)*(num_element + 1));
	for (i = 1; i <= num_element; i++) {
		EEL[i] = (long int*)malloc(sizeof(long int)*(num_element + 1));
		EER[i] = (long int*)malloc(sizeof(long int)*(num_element + 1));
		DDL[i] = (int*)malloc(sizeof(int)*(num_element + 1));
		DDR[i] = (int*)malloc(sizeof(int)*(num_element + 1));
		PPL[i] = (int*)malloc(sizeof(int)*(num_element + 1));
		PPR[i] = (int*)malloc(sizeof(int)*(num_element + 1));
	}
		
	i = 1;
	while (!feof(f)) {
		fscanf_s(f, "%d %d", &D[i], &W[i]);
		i++;
	}
	for (i = 1; i <= num_element; i++) {
		for (j = 1; j <= num_element; j++) {
			EEL[i][j] = INFI;
			EER[i][j] = INFI;
			DDL[i][j] = 0;
			DDR[i][j] = 0;
			PPL[i][j] = 0;
			PPR[i][j] = 0;
		}
	}

}
void min_energy(int s_number,int L, int R) {
	int i, j;
	EEL[s_number][s_number] = 0;
	EER[s_number][s_number] = 0;
	i = s_number;
	j = s_number;
	for (diagonal = 1; diagonal < num_element; diagonal++) {
		for (i = 1; i <= num_element-diagonal; i++) {
			j = i + diagonal;
			EEL[i][j] = findminimum_L(i, j);
			//printf("EEL[%d][%d]=%d\n", i, j, EEL[i][j]);
			EER[i][j] = findminimum_R(i, j);
			//printf("EER[%d][%d]=%d\n", i, j, EER[i][j]);
		}
	}


}
int findminimum_L(int L, int R) {
	int a, b;
	a = EEL[L + 1][R] + (DDL[L + 1][R] + D[L + 1] - D[L])*W[L];
	b = EER[L + 1][R] + (DDR[L + 1][R] + D[R] - D[L])*W[L];
	
	if (a <= b) {
		DDL[L][R] = DDL[L + 1][R] + D[L + 1] - D[L];
		PPL[L][R] = L + 1;
		//printf("PPL[%d][%d]=%d\n", L, R, PPL[L][R]);
		return a;
	}
	else {
		DDL[L][R] = DDR[L + 1][R] + D[R] - D[L];
		PPL[L][R] = R;
		//printf("PPL[%d][%d]=%d\n", L, R, PPL[L][R]);
		return b;
	}
		
}
int findminimum_R(int L, int R) {
	int a, b;
	a = EEL[L][R-1] + (DDL[L][R - 1] + D[R] - D[L])*W[R];
	b = EER[L][R - 1] + (DDR[L][R - 1] + D[R] - D[R-1])*W[R];

	if (a <= b) {
		DDR[L][R] = DDL[L][R - 1] + D[R] - D[L];
		PPR[L][R] = L;
		//printf("PPR[%d][%d]=%d\n", L, R, PPR[L][R]);
		return a;
	}
	else {
		DDR[L][R] = DDR[L][R - 1] + D[R] - D[R - 1];
		PPR[L][R] = R-1;
		//printf("PPR[%d][%d]=%d\n", L, R, PPR[L][R]);
		return b;
	}
}
void print_output(FILE *f,int L,int R) {
	int a, b,min_e;
	if (L == 1 && R == num_element) {
		a = EEL[L][R];
		b = EER[L][R];
		if (a <= b)
			min_e = a;
		else
			min_e = b;
		//printf("Àü·Â ÃÖ¼Ú°ª: %d\n", min_e);
		fprintf_s(f, "%d\n", min_e);
	}
	if (min_e == a)
		print_path(f, 1, num_element, L);
	else
		print_path(f, 1, num_element, R);

}
void print_path(FILE *f, int L, int R,int last) {
	if (last != start_number) {
		if (last == L)
			print_path(f,L + 1, R, PPL[L][R]);
		else if (last == R)
			print_path(f,L, R - 1, PPR[L][R]);
	}
	//printf("%d\n", last);
	fprintf_s(f,"%d\n", last);
}
void m_free() {
	int i;
	for (i = 1; i <= num_element; i++) {
		free(EEL[i]);
		free(EER[i]);
		free(DDL[i]);
		free(DDR[i]);
		free(PPL[i]);
		free(PPR[i]);
	}
	free(EEL);
	free(EER);
	free(DDL);
	free(DDR);
	free(PPL);
	free(PPR);
	free(D);
	free(W);
}