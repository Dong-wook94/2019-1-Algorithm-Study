#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;//N�� ������ ���� ����, K�� ���ؾ��� index
vector<int> A;//�迭
int main() {
	int input;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		A.push_back(input);
	}
	sort(A.begin(), A.end());
	printf("%d", A[K - 1]);
}