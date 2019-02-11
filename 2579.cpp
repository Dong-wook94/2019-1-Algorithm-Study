#include <stdio.h>
#include <stdlib.h>
typedef struct Step {
	int score;
	int before;
}Step;

Step *step;


int max(int a, int b, int i);
int main() {
	int steps_num;
	int step_score;
	int i;
	scanf("%d", &steps_num);
	step = (Step*)malloc(sizeof(Step)*(steps_num + 1));
	for (i = 0; i <= steps_num; i++) {
		step[i].score = 0;
	}

	scanf("%d", &step_score);

	step[1].score += step_score;
	step[1].before = 1;//시작점은 계단에서포함안되서 본인이 before 계단이라 설정

	for (i = 2; i <= steps_num; i++) {
		scanf("%d", &step_score);
		step[i].score = max(step[i - 1].score, step[i - 2].score, i) + step_score;
		if (step[step[i].before].before == i - 2) {
			step[i].score = step[i - 2].score + step_score;
			step[i].before = i - 2;
		}

	}
	printf("%d", step[steps_num]);
}

int max(int a, int b, int i) {
	if (a > b) {
		step[i].before = i - 1;
		return a;
	}
	else {
		step[i].before = i - 2;
		return b;
	}
}