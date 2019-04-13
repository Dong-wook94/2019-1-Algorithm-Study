#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int N;
int Arr[21][21];
vector<int> comb;
int sumA, sumB;
int combination();
int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &Arr[i][j]);

		}
	}
	printf("%d", combination());
}
int combination() {
	int sum = 0;
	int min = INT_MAX;
	for (int i = 0; i < N / 2; i++) {
		comb.push_back(1);
		comb.push_back(0);
	}
	sort(comb.begin(), comb.end());
	
	do {
		sumA = 0;
		sumB = 0;
		for (int i = 1; i <=N; i++) {
			for (int j = 1; j <= N; j++) {
				if (comb[i - 1] == 1 && comb[j - 1] == 1)
					sumA += Arr[i][j];
				else if (comb[i - 1] == 0 && comb[j - 1] == 0)
					sumB += Arr[i][j];
			}
		}
		if (min > abs(sumA - sumB))
			min = abs(sumA - sumB);
	} while (next_permutation(comb.begin(), comb.end()));
	return min;
}