#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
int T, N;//T : x테스트케이스 개수 ,N : 순열의 크기
vector<vector<int>> graph;
int visited[1001];
void cnt_cycle();
void DFS(int start);
int cnt =0;
int main() {
	int i;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {//테스트 케이스 수만큼 반복
		cnt_cycle();
	}
	
	
}

void cnt_cycle() {
	int i, input;
	scanf("%d", &N);
	cnt = 0;
	memset(visited, 0, sizeof(visited));//0으로 초기화
	graph.assign(N + 1, vector<int>(0, 0));
	for (i = 1; i <= N; i++) {
		scanf("%d", &input);
		graph[i].push_back(input);
	}
	for (i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt++;
			DFS(i);
		}
	}
	printf("%d\n", cnt);
}
void DFS(int start) {
	int i;
	visited[start] = 1;
	for (i = 0; i < graph[start].size(); i++) {
		if (!visited[graph[start][i]]) {
			DFS(graph[start][i]);
		}
	}
}