#include <stdio.h>

typedef struct Wheel {
	int tooth[8];
	int dir;
	int score;
}Wheel;
Wheel wheel[4];
int num_turn;//ȸ��Ƚ��
//int turn_rule[100][2];//ȸ����� 0:��Ϲ�����ȣ 1: ����(1 �ð���� 2:�ݽð�پ餷
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
void Turn(int num_wheel, int direction) {//��Ϲ��� ��ȣ -1�ؼ��ֱ�
	int temp;
	init_dir();//
	wheel[num_wheel].dir = direction;

	//��Ϲ��� �����ʹ��⼳��
	for (int i = num_wheel;i<3; i++) {
		if (wheel[i].tooth[2] == wheel[i + 1].tooth[6]) //�������϶�
			break;
		else {//�ٸ����϶�
			wheel[i + 1].dir = -1 * wheel[i].dir;
		}
	}
	//��Ϲ��� ���ʹ��⼳��
	for (int i = num_wheel; i>0; i--) {
		if (wheel[i].tooth[6] == wheel[i - 1].tooth[2]) //�������϶�
			break;
		else {//�ٸ����϶�
			wheel[i - 1].dir = -1 * wheel[i].dir;
		}
	}
	//��Ϲ��� ����
	
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