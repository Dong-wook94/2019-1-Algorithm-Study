#include <stdio.h>
#include <stdlib.h>
int num_element;
int *col;
void file_input(char *a);
void file_output();
void matrix_set();
void procedure_queens(int i);
int promising(int i);
void print_position(FILE *f);
int main() {
	char input_n[100];

	printf("input file name?");
	gets_s(input_n, sizeof(input_n));
	file_input(input_n);
	matrix_set();
	procedure_queens(0);
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
	for (i = 1; i <= num_element; i++)
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
	/*for (k = 1; k <= num_element; k++) {
		printf("%d", col[k]);
		if (num_element == k)
			printf("\n");
	}*/
	if (promising(i)) {
		if (i == num_element)
		{
			file_output();
			exit(1);
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
int promising(int i) {
	int k = 1;
	int promising = 1;

	while (k < i&&promising) {
		if ((col[i] == col[k]) || abs(col[i] - col[k]) == abs(i - k))
			promising = 0;
		k++;
	}
	return promising;

}
void print_position(FILE *f) {
	int i;
	for (i = 1; i <= num_element; i++) {
		fprintf_s(f, "%d\n", col[i]);
		//printf("col[%d] : %d\n", i, col[i]);
	}
}
