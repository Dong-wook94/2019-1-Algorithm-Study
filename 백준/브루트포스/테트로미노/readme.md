# 14500번 테트로미노

> 브루트포스, dfs이용, 삼성 sw 역량테스트 기출문제

ㅗ모양을 제외한 나머지 블록묘양에서 dfs를 활용할수있음을 인지하고 코드를 
짠건 괜찮은 아이디어였으나 visited 초기화 부분에서 시간초과가 발생해 
수정을했다. 첨에는 모든 배열을 다시 재초기화 하는 방법을 사용하여 시간 
초과가 났지만 

~~~
void dfs(int row, int col,int block_cnt,int sum) {
	int next_row;
	int next_col;
	//visited[row][col] = 1;
	if (block_cnt == 3) {
		if (max_sum < sum)
			max_sum = sum;
		return;
	}
	visited[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		next_row = row + dir_row[i];
		next_col = col + dir_col[i];
		if (next_row >= 0 && next_col >= 0 && next_row < 
N&&next_col < M&&visited[next_row][next_col]==0) {
			//visited[next_row][next_col] = 1;
			dfs(next_row, next_col, block_cnt + 1, sum + 
map[next_row][next_col]);
			//visited[next_row][next_col]=0;
		}
		
	}
	visited[row][col] = 0;
}
~~~
visited 위치를 위의 코드처럼 초기화함으로써 시간초과를 해결하였다

예외인 도형 ㅗ는 ㅓ,ㅏ,ㅗ,ㅜ 마다 따로 처리하여 하드코딩하였다.

[백준 14500번 테트로미노](https://www.acmicpc.net/problem/14500)
