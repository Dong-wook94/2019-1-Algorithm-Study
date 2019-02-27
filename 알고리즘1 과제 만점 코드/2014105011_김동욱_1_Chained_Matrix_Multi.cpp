#include <stdio.h>
#include <stdlib.h>
#define INFI 1000000000
long int **m;
int **p;
int *element_array;
int diagonal,num_element;
void matrix_set(FILE *f);
void minmult();
void print_order(FILE *f,int i, int j);
int find_minimum(int f,int l);
void m_free();
int main() {
	char input_n[100];
	FILE *f_in;
	FILE *f_out;
	errno_t err_in;
	errno_t err_out;

	printf("input file name?");
	gets_s(input_n, sizeof(input_n));
	err_in = fopen_s(&f_in,input_n,"r");
	matrix_set(f_in);
	fclose(f_in);

	minmult();

	err_out = fopen_s(&f_out, "output.txt", "w");
	print_order(f_out,1, num_element-1);
	fclose(f_out);
	m_free();
	return 0;
}
void matrix_set(FILE *f) {
	int i,j;
	fscanf_s(f, "%d", &num_element);
	element_array = (int*)malloc(sizeof(int)*num_element);
	m = (long int**)malloc(sizeof(long int*)*num_element);
	p = (int**)malloc(sizeof(int*)*num_element);
	for (i = 0; i < num_element; i++) {
		m[i] = (long int*)malloc(sizeof(long int)*num_element);
		p[i] = (int*)malloc(sizeof(int)*num_element);
	}
		
	i = 0;
	while (!feof(f))
	{
		fscanf_s(f, "%d", &element_array[i]);
		i++;
	}
	for (i = 1; i < num_element; i++) {
		for (j = i; j <num_element; j++) {
			m[i][j] = INFI;
		}
	}

}
void minmult(void){
	int i, j;
	for (i = 1; i < num_element; i++)
		m[i][i] = 0;
	for (diagonal = 1; diagonal < num_element - 1; diagonal++) {
		for (i = 1; i < num_element - diagonal; i++) {
			j = i + diagonal;
			p[i][j]=find_minimum(i, j);
			//printf("m[%d][%d]=%d,p[%d][%d]=%d\n", i, j, m[i][j],i,j,p[i][j]);
		}
	}
}
int find_minimum(int f,int l) {
	int a=0,b=1;
	int i;
	for (i = f; i < l; i++) {
		a = m[f][i] + m[i+1][l] + element_array[f - 1] * element_array[i] * element_array[l];
		if (a < m[f][l]) {
			m[f][l] = a;
			b = i;
		}
	}
	return b;
}
void print_order(FILE *f,int i, int j){
	if (i == j) {
		//printf("%d ", i);
		fprintf_s(f, "%d ",i);
	}
	else
	{
		//printf("(");
		fprintf_s(f, "(");
		print_order(f,i, p[i][j]);
		print_order(f,p[i][j] + 1, j);
		//printf(")");
		fprintf_s(f, ")");
	}
}
void m_free() {
	int i;
	for (i = 0; i < num_element; i++) {
		free(m[i]);
		free(p[i]);
	}
	free(m);
	free(p);
	free(element_array);
}