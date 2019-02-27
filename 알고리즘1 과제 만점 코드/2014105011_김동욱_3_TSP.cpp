#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX 30000
typedef struct Vertex {
	int bound;
	int level;
	int *path;
}Vertex;


Vertex *heap;
int cur_heapsize;
int max_heapsize;
int num_element;
int **matrix;
int **temp_matrix;
int *opt_tour;
void file_input(char *a);
void matrix_set(FILE *f);
void file_output();
Vertex CreateNode(int pathsize);
void heapInit(int size);
int heapFull();
int heapEmpty();
void insertHeap(Vertex item);
Vertex removeHeap();
int bound(Vertex v);
int TSP();
int length(int *path);


int main() {
	char input_n[100];
	int minlength;

	printf("input file name?");
	gets_s(input_n, sizeof(input_n));
	file_input(input_n);//이까지하면 matrixsetting까지 완료
	//이제 
	heapInit(num_element);
	minlength = TSP();
	file_output();
	//printf("minlength : %d", minlength);
	//printf("weight : %d",)
	return 0;
}
void file_input(char *input_n) {
	FILE *f_in;
	errno_t err_in;
	//int i;

	err_in = fopen_s(&f_in, input_n, "r");
	fscanf_s(f_in, "%d", &num_element);
	matrix_set(f_in);
	fclose(f_in);

}
void matrix_set(FILE *f) {
	int i,j;

	
	matrix = (int**)malloc(sizeof(int*)*(num_element+1));
	temp_matrix = (int**)malloc(sizeof(int*)*(num_element+1));
	for (i = 0; i <= num_element; i++) {
		matrix[i] = (int*)malloc(sizeof(int)*(num_element+1));
		temp_matrix[i] = (int*)malloc(sizeof(int)*(num_element + 1));
	}
	opt_tour = (int*)malloc(sizeof(int)*(num_element + 1));

	for (i = 1; i <= num_element; i++) {
		for (j = 1; j <= num_element; j++)
		{
			fscanf_s(f,"%d", &matrix[i][j]);
		}
	}
	/*for (i = 0; i < num_element; i++) {
		for (j = 0; j < num_element; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}*/
}
Vertex CreateNode(int pathsize) {
	Vertex temp;
	int i;

	temp.bound = 0;//temp bound 0으로 초기화
	temp.path = (int*)malloc(sizeof(int)*pathsize);//pathsize 는 시작할때 나중에 변수로 num_element추가하자
	for (i = 0; i <= pathsize; i++)//나중에 path입력할때 까먹지말고 1부터
		temp.path[i] = 0;

	return temp;
}
void heapInit(int size) {//여기서 heap 메모리할당해주고 max_heapsize와 cur_heapsize 초기화
	heap = (Vertex*)malloc(sizeof(Vertex)*(size + 1));
	max_heapsize = size;
	cur_heapsize = 0;
}
int heapFull() {
	int full = FALSE;

	if (cur_heapsize == max_heapsize)
		full = TRUE;
	return full;
}
int heapEmpty() {
	int empty = FALSE;

	if (cur_heapsize == 0)
		empty = TRUE;
	return empty;
}
void insertHeap(Vertex item) {
	int i, temp;
	Vertex tempN;
	
	if (cur_heapsize == max_heapsize) {
		heap = (Vertex*)realloc(heap, sizeof(Vertex) * (2 * max_heapsize + 1));
		max_heapsize *= 2;
	}

	heap[cur_heapsize + 1] = item;
	cur_heapsize++;

	if (cur_heapsize > 1)
	{
		for (i = cur_heapsize; i >= 2; i /= 2) {
			temp = i / 2;
			if (heap[temp].bound > heap[i].bound)
			{
				tempN = heap[temp];
				heap[temp] = heap[i];
				heap[i] = tempN;
			}
		}
	}
	
}

Vertex removeHeap()
{
	Vertex temp, tempN;
	int left, right, child, i = 1, flag = 0;
	
	if (heapEmpty() != 1)
	{
		temp = heap[1];

		tempN = heap[cur_heapsize];
		heap[cur_heapsize].bound = MAX;
		heap[1] = tempN;

		cur_heapsize--;

		if (cur_heapsize > 1)
		{
			while (i <= (cur_heapsize / 2))
			{
				left = i * 2;
				right = left + 1;
				if (heap[left].bound > heap[right].bound)
				{
					flag = 1;
					child = right;
				}
				else
				{
					flag = 0;
					child = left;
				}

				if (heap[child].bound < heap[i].bound)
				{
					tempN = heap[i];
					heap[i] = heap[child];
					heap[child] = tempN;
				}

				if (flag == 0)
					i *= 2;
				else
					i = i * 2 + 1;
			}
		}
		return temp;
	}
	else
		return heap[0];
}
int existPath(Vertex v, int vertax) {
	int good = 0;
	int i;

	for (i = 1; i <= v.level; i++)
	{
		if (v.path[i] == vertax)
			good = 1;
	}
	return good;
}
int bound(Vertex v) {
	int temp = 0;
	int minvalue = MAX;
	int i, j, k;
	int column, row;

	for (i = 1; i <= num_element; i++)
		for (j = 1; j <= num_element; j++)
			temp_matrix[i][j] = matrix[i][j];
	if (v.level == 1)
	{
		for (i = 1; i <= num_element; i++)
		{
			minvalue = MAX;
			for (j = 1; j <= num_element; j++)
			{
				if (matrix[i][j] < minvalue && i!= j)
					minvalue = matrix[i][j];
			}
			temp += minvalue;
		}
	}
	else
	{
		for (k = 1; k <= num_element; k++)
		{
			row = v.path[k];
			column = v.path[k + 1];

			if (column == 0 && row != 0) {
				temp_matrix[row][1] = 0;
			}

			if (column != 0 && row != 0) {
				for (i = 1; i <= num_element; i++)
				{
					if (column != 0)
						temp_matrix[i][column] = 0;

					for (j = 1; j <= num_element; j++)
					{
						if (row != 0 && column != 0)
							temp_matrix[row][j] = 0;
					}
				}
			}
		}
		for (i = 1; i <= num_element; i++) {
			minvalue = MAX;

			for (j = 1; j <= num_element; j++)
			{
				if (matrix[i][j] < minvalue && temp_matrix[i][j] != 0)
					minvalue = matrix[i][j];
			}
			if (minvalue != MAX)
				temp += minvalue;
			row = v.path[i];
			column = v.path[i + 1];

			if (row != 0 && column != 0)
				temp += matrix[row][column];
		}
	}
	return temp;
}
int length(int* path)
{
	int temp = 0, i;
	for (i = 1; i<num_element; i++)
	{
		temp += matrix[path[i]][path[i+1]];
	}
	temp += matrix[path[i]][path[1]];

	return temp;
}
int TSP() {
	Vertex v,u;
	int i, j;
	int minlength = MAX;
	v = CreateNode(num_element + 1);
	v.level = 1;
	v.path[1] = 1;
	v.bound = bound(v);
	insertHeap(v);

	while (!heapEmpty()) {
		v = removeHeap();

		if (v.bound < minlength)
		{
			if (v.level == num_element)
			{
				for (j = 1; j <= v.level; j++)
					opt_tour[j] = v.path[j];
				minlength = length(opt_tour);
			}
			for (i = 2; i <= num_element; i++)
			{
				if (!existPath(v, i))//path가 존재하는지 확인
				{
					u = CreateNode(num_element + 1);
					u.level = v.level+1;
					for (j = 1; j <= v.level; j++)
						u.path[j] = v.path[j];
					u.path[u.level] = i;
					u.bound = bound(u);
					if (u.bound < minlength)
						insertHeap(u);
				}
			}
		}
		
	}
	return minlength;
}
void file_output() {
	FILE *f_out;
	errno_t err_out;
	int i;
	err_out = fopen_s(&f_out, "output.txt", "w");

	for (i = 1; i <= num_element; i++) {
		fprintf_s(f_out, "%d\n", opt_tour[i]);
		//printf("%d\n", opt_tour[i]);
	}
	fprintf_s(f_out, "1");
	//printf_s("1\n");
	for (i = 0; i <= num_element; i++)
	{
		free(matrix[i]);
		free(temp_matrix[i]);
	}
	free(opt_tour);
	free(heap);
	free(matrix);
	free(temp_matrix);

	fclose(f_out);

	

}