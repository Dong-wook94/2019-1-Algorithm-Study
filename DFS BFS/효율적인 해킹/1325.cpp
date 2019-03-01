#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int>cnt_hack;
int N, M; // N은 컴퓨터 개수 M은 관계개수
void DFS(int start);
int Max=0;
int main() {
	int i,a,b;
	scanf("%d %d", &N, &M);
	//visited.assign(N+1, 0);//N+1개의 배열을 0으로 초기화
	cnt_hack.assign(N+1, 0);//N+1개의 배열을 0으로 초기화
	graph.assign(N+1, vector<int>(0, 0));
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}
	for (i = 1; i <=N; i++) {
		visited.assign(N+1, 0);
		DFS(i);
	}
	for (i = 1; i <= N; i++) {
		printf("%d:  %d\n", i, cnt_hack[i]);
	}
	
	for (i = 1; i <=N; i++) {
		if (Max == cnt_hack[i])
			printf("%d\n", i);
	}
}

void DFS(int start) {
	int i;
	cnt_hack[start]++;
	if (Max < cnt_hack[start])
		Max = cnt_hack[start];
	visited[start] = 1;
	for (i = 0; i < graph[start].size(); i++) {
		if (!visited[graph[start][i]]) {
			DFS(graph[start][i]);
		}
	}
}