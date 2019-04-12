# 15684번 사다리조작

> dfs이용, 브루트포스, 삼성 sw 역량테스트 기출문제

 dfs를 이용하여 사다리를 놓는다. 그리고 경우를 다따지는 브루트포스 문제.
여기서 dfs안에서 사다리를 놓을때 이전에 사다리를 놓았던 이전 row들은 
볼필요없다. 이를 무시하고 1부터 탐색했을때 시간초과가 발생하였다.

~~~
void dfs(int row_start,int end_time,int cur_time) {
	int next_row;
	int next_col;
	if (cur_time == end_time) {
		if (correct_check()) {
			printf("%d\n", cur_time);//최소값 갱신필요없이
			exit(0);
		}
		return; //dfs 종료
	}
	for (int next_row = row_start; next_row <=H; next_row++) {
		for (int next_col = 1; next_col < N; next_col++) {
			if (ladder[next_row][next_col - 1] == 0 && 
ladder[next_row][next_col] == 0 && ladder[next_row][next_col + 1]==0) {
				ladder[next_row][next_col] = 1;
				dfs(next_row,end_time, cur_time + 1);
				ladder[next_row][next_col] = 0;
			}
		}
	}

}
~~~
dfs를 돌릴때 next_row를 계속 넘겨줌으로써 시간을 단축하였다.

[백준 15684번 사다리조작](https://www.acmicpc.net/problem/15684)

