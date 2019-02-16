#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

#define TRUE 1
#define FALSE 0
using namespace std;

int *building;
vector <int> build_time;
vector<vector<int>> build_order;
vector<int> min_build_time;
void ACM_Craft();
vector<int> precnt;
queue<int> q;
int Max(int a, int b);
int main() {
	int testcase_num;
	int i;

	scanf("%d", &testcase_num);

	for (i = 0; i < testcase_num; i++) {
		ACM_Craft();
	}
}
void ACM_Craft(){
	int n_building, n_rule, i,f_building;
	int input,a,b;

	scanf("%d %d", &n_building, &n_rule);

	building = (int*)malloc(sizeof(int)*(n_building + 1));
	build_time.push_back(0);
	build_order.assign(n_building + 1, vector<int>(1,0));
	precnt.assign(n_building + 1,0);
	for (i = 1; i <= n_building; i++) {
		scanf("%d", &input);
		build_time.push_back(input);
	}
	for (i = 0; i < n_rule; i++) {
		scanf("%d %d", &a, &b);
		build_order[a].push_back(b);
		precnt[b]++;
	}
	scanf("%d", &f_building);
	
	/*for (i = 1; i < build_order.size(); i++) {
		printf("%d : ", i);
		for (a = 0; a < build_order[i].size(); a++) {
			printf("%d ", build_order[i][a]);
		}
		printf("\n");
	}*/
	min_build_time.assign(n_building + 1, 0);
	for (i = 1; i <= n_building; i++) {
		if (precnt[i] == 0) {
			q.push(i);
		}
	}
	while (precnt[f_building] > 0) {
		a = q.front();
		q.pop();

		for (i = 1; i < build_order[a].size(); i++) {//모든 후행자의 최소 건설시간
			b = build_order[a][i];
			min_build_time[b] = Max(min_build_time[b], min_build_time[a] + build_time[a]);
			precnt[b]--;
			if (precnt[b] == 0) q.push(b);
		}
	}
	min_build_time[f_building] = min_build_time[f_building] + build_time[f_building];
	printf("%d\n", min_build_time[f_building]);
	
	free(building);
	build_time.clear();
	build_order.clear();
	min_build_time.clear();
	precnt.clear();
	while (!q.empty()) q.pop();
}
int Max(int a, int b) {
	if (a > b) return a;
	else return b;
}