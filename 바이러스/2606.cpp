#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int n_com;//컴퓨터 수
int n_connect;//네트워크 상에서 직접 연결되어 있는컴퓨터 쌍의수

vector<vector<int>> connection;
int cnt = 0;
void dfs(int s);
int *visited;
int main() {
	int i,a,b;
	scanf("%d", &n_com);
	scanf("%d", &n_connect);

	//세로줄갯수는 해당번호와 일치하는 인덱스를 가지기위해 n_com+1로 설정
	connection.assign(n_com + 1, vector<int>(1, 0));//초기에는 가로줄 첫번째에 0으로초기화된 배열 한칸만존재
	visited = (int*)calloc(n_com + 1, sizeof(int));
	for (i = 0; i < n_connect; i++) {
		scanf("%d %d", &a,&b);
		connection[a].push_back(b);
		connection[b].push_back(a);//혹시 입력이 어떻게들어올지모르니 두방향다 설정해놓음
	}
	dfs(1);
	printf("%d\n", cnt);
	
}

void dfs(int s) {
	int i;
	visited[s] = 1;//방문했으면 1로
	cnt++;
	for (i = 1; i < connection[s].size(); i++) {
		if (!visited[connection[s][i]]) {
			dfs(connection[s][i]);
		}
	}
}