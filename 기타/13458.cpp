#include <stdio.h>

int N;//������ ����
int A[1000000];//�����忡 �ִ� �����ڼ�
int B, C;//B �Ѱ������� �����Ҽ� �ִ� �����ڼ�, C: �ΰ������� �����Ҽ��ִ� �����ڼ�
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