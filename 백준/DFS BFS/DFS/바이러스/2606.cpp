#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int n_com;//��ǻ�� ��
int n_connect;//��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ���ǻ�� ���Ǽ�

vector<vector<int>> connection;
int cnt = 0;
void dfs(int s);
int *visited;
int main() {
	int i,a,b;
	scanf("%d", &n_com);
	scanf("%d", &n_connect);

	//�����ٰ����� �ش��ȣ�� ��ġ�ϴ� �ε����� ���������� n_com+1�� ����
	connection.assign(n_com + 1, vector<int>(1, 0));//�ʱ⿡�� ������ ù��°�� 0�����ʱ�ȭ�� �迭 ��ĭ������
	visited = (int*)calloc(n_com + 1, sizeof(int));
	for (i = 0; i < n_connect; i++) {
		scanf("%d %d", &a,&b);
		connection[a].push_back(b);
		connection[b].push_back(a);//Ȥ�� �Է��� ��Ե������𸣴� �ι���� �����س���
	}
	dfs(1);
	printf("%d\n", cnt);
	
}

void dfs(int s) {
	int i;
	visited[s] = 1;//�湮������ 1��
	cnt++;
	for (i = 1; i < connection[s].size(); i++) {
		if (!visited[connection[s][i]]) {
			dfs(connection[s][i]);
		}
	}
}