#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char arr1[1001];
char arr2[1001];
int dp[1001][1001];
int main() {
	int i, j;
	scanf("%s", arr1);
	scanf("%s", arr2);
	
	for (i = 1; i <= strlen(arr1); i++) {
		for (j = 1; j <= strlen(arr2); j++) {
			if (arr1[i - 1] == arr2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	/*for (i = 0; i <= strlen(&arr1[1]); i++) {
		for (j = 0; j <= strlen(&arr2[1]); j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n", dp[strlen(arr1)][strlen(arr2)]);
	

	return 0;
}
	