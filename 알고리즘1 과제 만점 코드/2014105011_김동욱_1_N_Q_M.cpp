#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define D_NUM 5
int num_element;
int *col;
time_t startTime;

//long cntl=0;
void file_input(char *a);
void file_output();
void matrix_set();
void procedure_queens(int i);
void montecarlo_n_queens();
int promising(int i);
void print_position(FILE *f);
int main() {
	char input_n[100];
	int cnt = 0;

	//startTime = clock();
	printf("input file name?");
	gets_s(input_n, sizeof(input_n));
	file_input(input_n);
	matrix_set();
	srand(time(NULL));
	while(1){
		//printf("%d\n", cnt);
		montecarlo_n_queens();
	//	cnt++;
	}
	//file_output();
	//matrix_free();
	return 0;

}
void file_input(char *input_n) {
	FILE *f_in;
	errno_t err_in;

	err_in = fopen_s(&f_in, input_n, "r");
	fscanf_s(f_in, "%d", &num_element);
	//printf("num_element : %d", num_element);
	fclose(f_in);

}
void matrix_set() {
	int i;

	col = (int*)malloc(sizeof(int)*(num_element + 1));
	for (i = 0; i <= num_element; i++)
		col[i] = 0;
		
}
void file_output() {
	FILE *f_out;
	errno_t err_out;

	err_out = fopen_s(&f_out, "output.txt", "w");
	print_position(f_out);
	fclose(f_out);
	free(col);
}
void procedure_queens(int i) {
	int j;
	if (promising(i)) {
		if (i == num_element)
		{
			file_output();
			//printf("END_TIME : %d\n", (clock() - startTime) / CLOCKS_PER_SEC);
			exit(0);
		}
		else
		{
			for (j = 1; j <= num_element; j++) {
				col[i + 1] = j;
				procedure_queens(i + 1);
			}
		}
	}
}
void montecarlo_n_queens() {
	int i, j,temp,temp2;
	temp = 0;
	temp2 = 0;
	i = 1;
	

	if (num_element > D_NUM) {
		while (i<=(num_element- D_NUM)) {
			j = (rand() % num_element) + 1;
			col[i] = j;

			if (promising(i)) {
				temp = 0;
				i++;
			}
			
			if (temp >= num_element*0.95) {
				//printf("!");
				//cntl++;
				i = i*0.95;
				temp = 0;
				temp2++;
			}
			if (temp2 >= num_element *0.2) {
				//printf("@");
				i = 1;
				temp = 0;
				temp2 = 0;
			}

			temp++;
		}
	}
	else
		procedure_queens(0);
	procedure_queens(num_element - D_NUM);
}
int promising(int i) {
	int k = 1;
	int result = 1;

	while (k < i&&result) {
		if ((col[i] == col[k]) || abs(col[i] - col[k]) == abs(i - k))
			result = 0;
		k++;
	}
	return result;
	
}
void print_position(FILE *f) {
	int i;
	for (i = 1; i <= num_element; i++) {
		fprintf_s(f, "%d\n", col[i]);
		//printf("col[%d] : %d\n", i, col[i]);
	}
	//printf("!:%d", cntl);
}
