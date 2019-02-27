#include <stdio.h>
#include <stdlib.h>

typedef struct Level {
	int profit;
	int weight;
	//int efficiency;
}Level;

Level *level;
int num_element = 0;
int weight_limit,numbest,maxprofit;

int *bestset;
int *include = NULL;
void file_input(char *a);
void matrix_set();
void swap(Level*a, Level*b);
void quicksort(int left,int right);
int  promising(int i, int profit, int weight);
void knapsack(int i, int profit, int weight);
void file_output();
void print_bestset(FILE *f);

int main() {
	char input_n[100];

	printf("input file name?");
	scanf_s("%s", input_n, sizeof(input_n));
	file_input(input_n);
	numbest = 0;
	maxprofit = 0;
	knapsack(0, 0, 0);
	//printf("!!!");
	file_output();
	return 0;
}
void file_input(char *input_n) {
	FILE *f_in;
	errno_t err_in;
	int i;

	err_in = fopen_s(&f_in, input_n, "r");
	fscanf_s(f_in, "%d %d", &num_element,&weight_limit);
	matrix_set();
	//printf("num_element : %d", num_element);
	//printf("wineight_total : %d", weight_limit);
	for (i = 1; i <= num_element; i++) {
		fscanf_s(f_in, "%d %d", &level[i].profit, &level[i].weight);
		
	}
	//quicksort(1, num_element);
	fclose(f_in);

}
void matrix_set() {		

	int i;

	level = (Level*)malloc(sizeof(Level)*(num_element + 1));
	//w = (int*)malloc(sizeof(int)*(num_element+1));
	bestset = (int*)malloc(sizeof(int)*(num_element + 1));
	include = (int*)malloc(sizeof(int)*(num_element + 1));
	//printf("@@%d", (int)pow(2, num_element));
	for (i = 0; i <= num_element; i++) {
		level[i].profit = 0;
		level[i].weight = 0;
		bestset[i] = 0;
		include[i] = 0;
	}
	

}
void swap(Level*a, Level*b) {
	Level t = *a;
	*a = *b;
	*b = t;
}
void quicksort(int left, int right) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left > right) {
		for (; i <= right; i++) {
			if (level[i].profit / level[i].weight > level[pivot].profit / level[pivot].weight) {
				j++;
				swap(&level[j], &level[j]);
			}
		}
		swap(&level[left], &level[j]);
		pivot = j;

		quicksort(left, pivot - 1);
		quicksort(pivot + 1, right);
	}

}
int  promising(int i, int profit, int weight) {
	int result;
	int bound;
	int totweight;
	int j,k;
	if (level[i].weight >= weight_limit)
		result = 0;
	
	else {
		j = i + 1;
		if (j > num_element) return 0;
		bound = profit;
		totweight = weight;
		while (j <= num_element && (totweight + level[j].weight) < weight_limit) {
			totweight = totweight + level[j].weight;
			bound = bound + level[j].profit;
			j++;
			
		}
		k = j;
		if (k <= num_element) {
			bound += (weight_limit - totweight)*(level[k].profit / level[k].weight);
			//printf("%d : %lf\n", i,bound);
		}
		//printf("bound: %lf\n", bound);
		result = (bound > maxprofit);
	}
	return result;
}
void knapsack(int i,int profit,int weight) {
	int k;
	
	if (weight <= weight_limit && profit > maxprofit)
	{
		maxprofit = profit;
		numbest = i;
		//printf("%d p:%d,w:%d\n ",i, profit, weight);
		for (k = 1; k <= i; k++) {
			bestset[k] = include[k];
			//printf("%d\n",bestset[k]);
		}
	}
	if (weight > weight_limit) return;
	if (promising(i,profit, weight)) {
		if (i > num_element) return;
		include[i + 1] = 1;
		knapsack(i + 1, profit + level[i + 1].profit, weight + level[i + 1].weight);
		include[i + 1] = 0;
		knapsack(i + 1, profit, weight);
	}
	//printf("!\n");
}
void file_output() {
	FILE *f_out = NULL;
	errno_t err_out;
	err_out=fopen_s(&f_out, "output.txt", "w");
	//printf("%d\n", err_out);
	//printf("!!!");
	print_bestset(f_out);
	fclose(f_out);
	free(level);
	level = NULL;
	free(bestset);
	bestset = NULL;
	free(include);
}
void print_bestset(FILE *f) {
	int i;
	//printf("maxprofit :%d\n",maxprofit);
	//printf("numbest : %d\n", numbest);
	fprintf(f, "%d\n", maxprofit);
	for (i = 1; i <= numbest; i++) {
		fprintf(f,"%d\n", bestset[i]);
	}
	for (i = numbest + 1; i <= num_element; i++) {
		fprintf(f,"0\n");
	}
}
