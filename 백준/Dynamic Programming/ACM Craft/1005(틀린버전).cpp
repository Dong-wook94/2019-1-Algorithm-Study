#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Node *listPointer;
typedef struct Node {
	int num;
	listPointer link;
}Node;
typedef struct Queue {
	int *data;
	int front;
	int rear;
}Queue;
Queue order;
listPointer *building;
void ACM_Craft();
int *visited;
void q_push(int num);
int q_pop();
int q_order();
void bfs(int v);
int max(int num, int n_building, int min_time[]);
int main() {
	int testcase_num;
	int i;

	scanf("%d", &testcase_num);

	for (i = 0; i < testcase_num; i++) {
		ACM_Craft();
	}
}
void ACM_Craft(){
	int n_building, n_rule, i, a, b, f_building;
	int *build_time;
	int *min_time;
	listPointer temp, nextNode;

	scanf("%d %d", &n_building, &n_rule);

	building = (listPointer*)malloc(sizeof(listPointer)*(n_building + 1));//인접리스트위한 동적할당
	order.data = (int*)calloc(n_building+1,sizeof(int));//순서를 저장할 배열 
	visited = (int*)calloc(n_building + 1,sizeof(int));//할당하며 0(false)으로초기화
	build_time = (int*)malloc(sizeof(int)*(n_building+1));//건물별 시간
	min_time = (int*)calloc(n_building + 1, sizeof(int));//

	for (i = 1; i <= n_building; i++) {//시간입력받음
		scanf("%d", &build_time[i]);
		building[i] = (Node *)malloc(sizeof(Node));
		building[i]->link = NULL;
	}

	for (i = 0; i < n_rule; i++) {
		scanf("%d %d", &a, &b);
		//rule[a][b] = 1;
		for (nextNode = building[b]; nextNode->link; nextNode = nextNode->link);//끝찾기
		temp = (Node*)malloc(sizeof(Node));
		temp->num = a;
		temp->link = NULL;
		nextNode->link = temp;
		nextNode = nextNode->link;
	}
	scanf("%d", &f_building);

	
	order.front = 0;
	order.rear = 0;
	bfs(f_building);
	order.rear = 0;

	i = q_order();
	min_time[i] = build_time[i];
	while (order.front > 0) {
		i = q_order();
		min_time[i] = max(i, n_building, min_time) + build_time[i];
	}
	printf("%d\n", min_time[f_building]);
	free(build_time);
	free(building);
	free(min_time);
	free(order.data);
	free(visited);
}

int max(int num,int n_building,int min_time[]) {
	int i;
	listPointer nextNode;
	int max_time=0,time;
	
	for (nextNode = building[num]->link; nextNode; nextNode = nextNode->link) {
		time = min_time[nextNode->num];
		if (max_time < time) {
			max_time = time;
		}
	}
	return max_time;
}
void q_push(int num) {
	order.data[order.front++] = num;
}
int q_pop() {
	return order.data[order.rear++];
}
int q_order() {
	return order.data[--order.front];
}
void bfs(int v) {
	listPointer nextNode;
	order.front = 0;
	order.rear = 0;
	visited[v] = TRUE;
	q_push(v);
	while (1) {
		v = q_pop();
		if (v < 1)
			break;
		for (nextNode = building[v]->link; nextNode; nextNode = nextNode->link) {
			if (!visited[nextNode->num]) {
				q_push(nextNode->num);
				visited[nextNode->num]=TRUE;
			}
		}
	}
}