#include <stdio.h>

int N;//시험장 개수
int A[1000000];//시험장에 있는 응시자수
int B, C;//B 총감독관이 감시할수 있는 응시자수, C: 부감독관이 감시할수있는 응시자수
long long cnt;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		cnt++;
	}
	scanf("%d %d", &B,&C);
	for (int i = 0; i < N; i++) {
		A[i] = A[i] - B;
		if (A[i] > 0)
		{
			cnt += ((A[i]-1) / C);
			cnt++;
		}

	}
	printf("%lld\n", cnt);

}