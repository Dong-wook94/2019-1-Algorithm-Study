# 1890 : 점프 

> bfs/dfs에 포함되어있는 문제이지만 dp를 이용하여 해결

 처음 이문제를 접근할때는 bfs를 이용하였다. 하지만 bfs를 이용하게되면 queue에 엄청나게 많은 경로가 저장되어 메모리 초과가 발생한다 그래서 dp를 이용하여 문제를 해결하였다. 내가 해결한 방법이 dp라서 폴더도 dp폴더에 저장하였다.

또한 추가적으로 dp가 되게 큰값이 저장될수있어서 long long으로 만들었는데 이걸 출력할때 %lld 로 안하고 %d로 했다가 많은 실패를 경험하였다. 꼭 출력형식에 신경 써야된다. 

**이문제 해결시 유의사항 : **
~~~
 1. bfs시도시 메모리초과 
 2. 큰 dp 값을 고려하여 long long 사용
 3. long long 출력형식 %lld 
~~~

> 출력형식 정리

~~~
%u : long long을 +- 부호 없는 정수로 출력하고 싶을 때

%lld : signed long long 변수를 출력할 때 사용

%lli : long long 변수를 10진수로 출력함

%llo : long long 변수를 8진수로 출력함 

%llu : unsigned long long 변수를 출력할 때 사용

%llx : long long 변수를 16진수로 출력함

%d : int

%ld : long

%lld : long long

%f : float

%lf : double

%l_f long double
~~~

https://www.acmicpc.net/problem/1890
