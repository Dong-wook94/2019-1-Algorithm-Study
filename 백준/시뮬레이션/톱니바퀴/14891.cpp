#include <stdio.h>

typedef struct Wheel {
	int tooth[8];
	int dir;
	int score;
}Wheel;
Wheel wheel[4];
int num_turn;//회전횟수
//int turn_rule[100][2];//회전방법 0:톱니바퀴번호 1: 방향(1 시계방향 2:반시계바얗ㅇ
void init_dir();
void Turn(int num_wheel, int direction);
void printScore();
int main() {
	int wheel_num, turn_dir;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &wheel[i].tooth[j]);
		}
	}
	scanf("%d",&num_turn);
	for (int i = 0; i < num_turn; i++) {
		scanf("%d %d", &wheel_num, &turn_dir);
		Turn(wheel_num - 1, turn_dir);
		//printf("\n%d %d\n", wheel_num, turn_dir);
		/*for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 8; k++) {
				printf("%d", wheel[j].tooth[k]);
			}
			printf(" %d\n",wheel[j].dir);
		}*/
	}
	printScore();
}
void init_dir() {
	for (int i = 0; i < 4; i++) {
		wheel[i].dir = 0;
	}
}
void Turn(int num_wheel, int direction) {//톱니바퀴 번호 -1해서넣기
	int temp;
	init_dir();//
	wheel[num_wheel].dir = direction;

	//톱니바퀴 오른쪽방향설정
	for (int i = num_wheel;i<3; i++) {
		if (wheel[i].tooth[2] == wheel[i + 1].tooth[6]) //같은극일때
			break;
		else {//다른극일때
			wheel[i + 1].dir = -1 * wheel[i].dir;
		}
	}
	//톱니바퀴 왼쪽방향설정
	for (int i = num_wheel; i>0; i--) {
		if (wheel[i].tooth[6] == wheel[i - 1].tooth[2]) //같은극일때
			break;
		else {//다른극일때
			wheel[i - 1].dir = -1 * wheel[i].dir;
		}
	}
	//톱니바퀴 변경
	
	for (int i = 0; i < 4; i++) {
		
		if (wheel[i].dir == 1) {
			temp = wheel[i].tooth[7];
			for (int j = 6; j >= 0; j--) {
				wheel[i].tooth[j + 1] = wheel[i].tooth[j];
			}
			wheel[i].tooth[0] = temp;
		}
		else if(wheel[i].dir==-1){
			temp = wheel[i].tooth[0];
			for (int j = 0; j <=6; j++) {
				wheel[i].tooth[j] = wheel[i].tooth[j+1];
			}
			wheel[i].tooth[7] = temp;
		}
		else {
			continue;
		}
	}

}
void printScore() {
	int sum = 0;
	wheel[0].score = 1;
	wheel[1].score = 2;
	wheel[2].score = 4;
	wheel[3].score = 8;
	for(int i = 0; i < 4; i++) {
		if (wheel[i].tooth[0] == 1)
			sum += wheel[i].score;
	}
	printf("%d\n",sum);
}