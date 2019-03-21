# 14501번 퇴사

> dp문제, 삼성 기출문제


#### main 점화식 코드
~~~
for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (i - j >= schedule[j].term) {
				dp[i] = max(schedule[i].pay + dp[j], 
dp[i]);
				if (Max < dp[i])
					Max = dp[i];
			}
		}
	}
~~~

중요한 point는 상담날짜+상담기간이 상담날짜+1 보다 크면 상담이 
불가능하기때문에 (여기서 1을 더한이유는 상담기간이 1이면 그날 끝나기 
때문) 예외처리 해주어야한다.

[백준 14501번 퇴사](https://www.acmicpc.net/problem/14501)

