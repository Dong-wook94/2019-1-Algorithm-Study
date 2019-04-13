#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;//N은 정렬할 수의 갯수, K는 구해야할 index
vector<int> A;//배열
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