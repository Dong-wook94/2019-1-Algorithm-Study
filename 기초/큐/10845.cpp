#include <stdio.h>
#include <string.h>
int N;//명령의 수
typedef struct Queue {
	int arr[100000];
	int front;
	int back;
}Queue;
Queue q;
void Push(int input);
int Pop();
int Size();
int Empty();
int Front();
int Back();
int main() {
	char inst[20];
	int input;
	scanf("%d", &N);
	q.front = -1;
	q.back = -1;
	for (int i = 0; i < N; i++) {
		scanf("%s", inst);
		if (!strcmp(inst, "push")) {
			scanf("%d", &input);
			Push(input);
		}
		else if (!strcmp(inst, "pop")) {
			printf("%d\n", Pop());
		}
		else if (!strcmp(inst, "size")) {
			printf("%d\n", Size());
		}
		else if (!strcmp(inst, "empty")) {
			printf("%d\n", Empty());
		}
		else if (!strcmp(inst, "front")) {
			printf("%d\n",Front());
		}
		else if (!strcmp(inst, "back")) {
			printf("%d\n", Back());
		}
	}
}

void Push(int input) {
	q.arr[++q.back] = input;
}

int Pop() {
	if (q.back - q.front <= 0)
		return -1;
	else
		return q.arr[++q.front];
}
int Size() {
	return q.back - q.front;
}
int Empty() {
	if (q.back - q.front <= 0)
		return 1;
	else
		return 0;
}
int Front() {
	if (q.back - q.front <= 0)
		return -1;
	else
		return q.arr[q.front+1];
}
int Back() {
	if (q.back - q.front <= 0)
		return -1;
	else
		return q.arr[q.back];
}