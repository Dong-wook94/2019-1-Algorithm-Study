#include <stdio.h>
#include <stdlib.h>
#define INFI 1000000
int *num;
int min(int a, int b, int c);

int main() {
	int input_num;
	int i;
	scanf("%d", &input_num);

	num = (int*)calloc(input_num + 1, sizeof(int));

	num[1] = 0;
	num[2] = 1;
	num[3] = 1;
	for (i = 4; i <= input_num; i++) {
		num[i]=min((i % 3 == 0 ? num[i / 3] : INFI), (i % 2 == 0 ? num[i / 2] : INFI), num[i - 1]);
	}
	printf("%d", num[input_num]);

}

int min(int a, int b, int c) {
	int Min = a;
	if (Min > b) {
		Min = b;
	}
	if (Min > c) {
		Min = c;
	}
	return Min + 1;
}
