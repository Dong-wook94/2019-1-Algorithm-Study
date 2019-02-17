#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int n;//정수의 개수
using namespace std;
vector<int> max_sum;

int main() {
	int i,input;
	scanf("%d", &n);
	
	scanf("%d", &input);
	max_sum.push_back(input);
	for (i = 1; i < n; i++) {//이전까지의 합과 새로운값 과의 비교를통해 큰값을 최대합 배열에 저장
		scanf("%d", &input);
		max_sum.push_back(max(max_sum[i - 1] + input, input));//
	}
	//qsort 사용법 
	//정렬할 배열, 요소 개수, 요소 크기, 비교함수
	sort(max_sum.begin(), max_sum.end());
	
	printf("%d\n", max_sum.back());
}
