# 11066번 : 파일 합치기

> dp문제

~~~
dp[j][j + i] = min(dp[j][j + i], dp[j][m] + dp[m + 1][j + i] + sum[j + i] - sum[j - 1]);
~~~
코드의 이부분이 메인 점화식인데 점화식은 쉽게 세웠지만 초기값을 잘못잡아 고생했다. 

dp문제를 풀때는 초기값 신경쓰자.

https://www.acmicpc.net/problem/status/11066
