#include <stdio.h>
#include <stdlib.h>
typedef struct node *nodePointer;
typedef struct node {
	int num;
	nodePointer link;
}node;

nodePointer *student;
int *cnt_pre;
void print_order(int n_student);

int main() {
	int n_student, n_compare, i, a_student, b_student;
	nodePointer nextNode, temp;

	scanf("%d %d", &n_student, &n_compare);
	student = (nodePointer*)malloc(sizeof(nodePointer)*(n_student + 1));
	cnt_pre = (int*)calloc(n_student + 1, sizeof(int));
	for (i = 1; i <= n_student; i++) {
		student[i] = (node *)malloc(sizeof(node));
		student[i]->link = NULL;
	}
	for (i = 0; i < n_compare; i++) { //adjacency list 생성
		scanf("%d %d", &a_student, &b_student);
		cnt_pre[b_student]++;//b의 선행자수 ++
		for (nextNode = student[a_student]; nextNode->link; nextNode = nextNode->link);//끝찾기
		temp = (node*)malloc(sizeof(node));
		temp->num = b_student;
		temp->link = NULL;
		nextNode->link = temp;
		nextNode = nextNode->link;
	}
	print_order(n_student);
}

void print_order(int n_student) {
	int i,j;
	int pre_cnt;
	nodePointer nextNode, temp;
	for (j = 0; j < n_student; j++) {
		for (i = 1; i <= n_student; i++) {
			pre_cnt = cnt_pre[i];
			if (pre_cnt == 0) {
				printf("%d ", i);
				cnt_pre[i] = -1;
				for (nextNode = student[i]->link; nextNode; nextNode = nextNode->link) {
					cnt_pre[nextNode->num]--;
				}
			}
		}
	}
	
}