#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int n;//������ ����
using namespace std;
vector<int> max_sum;

int main() {
	int i,input;
	scanf("%d", &n);
	
	scanf("%d", &input);
	max_sum.push_back(input);
	for (i = 1; i < n; i++) {//���������� �հ� ���ο ���� �񱳸����� ū���� �ִ��� �迭�� ����
		scanf("%d", &input);
		max_sum.push_back(max(max_sum[i - 1] + input, input));//
	}
	//qsort ���� 
	//������ �迭, ��� ����, ��� ũ��, ���Լ�
	sort(max_sum.begin(), max_sum.end());
	
	printf("%d\n", max_sum.back());
}
