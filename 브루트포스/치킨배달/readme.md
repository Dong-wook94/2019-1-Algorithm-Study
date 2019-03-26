# 15686번: 치킨배달

> 조합을 구하는게 중점인 문제, 삼성 sw 역량테스트 기출문제

 조합을 구하는게 핵심이였다. 처음에는 조합으로 구성한 배열을 
구성하려다가 저장할 2차원 배열의 size를 잡는것에 오히려 더많은 시간을 
들이는 느낌이 들어서 임시로 조합된 배열을 저장할 배열에 저장한뒤 
최소시간을 구하는 방식으로 구현하였다.

~~~
void combination() {//조합구하기 비트마스크같은 느낌으로 조합을 
구하였다.
	for (int i = 0; i < M; i++)
		Select.push_back(1);
	for (int i = 0; i < (chicken.size() - M); i++)
		Select.push_back(0);
	sort(Select.begin(), Select.end());

	do {
		for (int i = 0; i < Select.size(); i++) {
			if (Select[i] == 1) {
				comb_chicken.push_back(chicken[i]);
			}
		}
		result = min(result, chicken_distance());//조합중에서도 
최소거리를 찾기위함.

		comb_chicken.clear();//초기화해줘야됨.
	} while (next_permutation(Select.begin(), Select.end()));

}
~~~

조합을 구하는 함수이다. 여기서 do while반복문안에 next_permutation이라는 
함수를 사용하였는데 이는 algorithm stl 중하나인데 자동으로 다음 순열을 
가리켜준다. 

![캡처](https://user-images.githubusercontent.com/36303777/54984029-53041580-4ff1-11e9-9d7d-e33fb8afbb70.PNG)


[백준 15686번 치킨배달](https://www.acmicpc.net/problem/15686)
