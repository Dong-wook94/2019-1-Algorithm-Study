# 9095번 1,2,3 더하기

> dp 문제

작은수의 모든경우에서 다음에 1,2,3이 오는 경우를 더한다고 생각하고 dp 적용. 

~~~
for (int i = 1; i < 11; i++) {
		if (i - 1 >= 0)
			dp[i] += dp[i - 1];
		if (i - 2 >= 0)
			dp[i] += dp[i - 2];
		if (i - 3 >= 0) {
			dp[i] += dp[i - 3];
		}
	}
~~~

https://www.acmicpc.net/problem/9095
