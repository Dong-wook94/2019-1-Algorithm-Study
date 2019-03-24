#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack {
	int *a;
	int ptr;
}Stack;
Stack stack;

void stack_init(int num) {

	stack.a = (int*)malloc(sizeof(int)*num);
	stack.ptr = 0;
}
void stack_push(int num) {

	stack.a[stack.ptr] = num;
	stack.ptr++;
}
void stack_pop() {
	if (stack.ptr - 1 < 0)
		printf("-1\n");
	else {
		printf("%d\n", stack.a[stack.ptr - 1]);
		stack.ptr--;
	}
}
void stack_size() {
	printf("%d\n", stack.ptr);
}
void stack_empty() {
	if (stack.ptr == 0)
		printf("1\n");
	else
		printf("0\n");
}
void stack_top() {
	if (stack.ptr == 0)
		printf("-1\n");
	else
		printf("%d\n", stack.a[stack.ptr - 1]);
}

int main() {

	int num;
	int i;
	int input;
	char inst[10];
	//Stack stack;
	scanf("%d", &num);
	stack_init(num);

	for (i = 0; i < num; i++) {
		scanf("%s", inst);
		if (!strcmp(inst, "push")) {
			scanf("%d", &input);
			stack_push(input);
		}
		else if (!strcmp(inst, "pop")) {
			stack_pop();
		}
		else if (!strcmp(inst, "size")) {
			stack_size();
		}
		else if (!strcmp(inst, "empty")) {
			stack_empty();
		}
		else if (!strcmp(inst, "top")) {
			stack_top();
		}
	}
	//free(stack);
}
