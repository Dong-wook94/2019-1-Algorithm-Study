#include <stdio.h>
#include <stdlib.h>

typedef struct count {
	int zero;
	int one;
}count;

count *c;

void fibo();
int main() {
	int input_num;
	int *input;
	int i;
	c = (count*)malloc(sizeof(count) * 41);
	fibo();
	scanf("%d", &input_num);
	input = (int*)malloc(sizeof(int)*input_num);
	for (i = 0; i < input_num; i++) {
		scanf("%d", &input[i]);
	}
	for (i = 0; i < input_num; i++) {
		printf("%d %d\n", c[input[i]].zero, c[input[i]].one);
	}
}

void fibo() {
	int i;
	c[0].zero = 1;
	c[0].one = 0;
	c[1].one = 1;
	c[1].zero = 0;

	for (i = 2; i <= 40; i++) {
		c[i].zero = c[i - 1].zero + c[i - 2].zero;
		c[i].one = c[i - 1].one + c[i - 2].one;
	}
}