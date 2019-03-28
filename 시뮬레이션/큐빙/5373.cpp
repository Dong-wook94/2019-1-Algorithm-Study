#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

typedef struct Cube {
	vector<vector<char>> U;
	vector<vector<char>> D;
	vector<vector<char>> F;
	vector<vector<char>> B;
	vector<vector<char>> L;
	vector<vector<char>> R;
}Cube;

Cube cube;
char rule[2];
void Turn(char p);//한번돌릴때
void turn_clockwise(vector<vector<char>>&phase,int num);//시계방향회전
void turn_phase(vector<vector<char>>&phase, vector<vector<char>>&up, vector<vector<char>>&down, vector<vector<char>>&left, vector<vector<char>>&right);//회전할때 그면,위아래좌우
void printPhase(vector<vector<char>>&phase);
int main() {
	int T;
	int num_turn;
	int dir;
	scanf("%d", &T);
	

	while (T--)
	{
		cube.U = vector<vector<char>>(3, vector<char>(3, 'w'));
		cube.D = vector<vector<char>>(3, vector<char>(3, 'y'));
		cube.F = vector<vector<char>>(3, vector<char>(3, 'r'));
		cube.B = vector<vector<char>>(3, vector<char>(3, 'o'));
		cube.L = vector<vector<char>>(3, vector<char>(3, 'g'));
		cube.R = vector<vector<char>>(3, vector<char>(3, 'b'));
		scanf("%d", &num_turn);
		while (num_turn--) {
			scanf("%s", rule);
			if (rule[1] == '-') 
				dir = 3;
			else 
				dir = 1;

			for (int i = 0; i < dir; i++) {
				Turn(rule[0]);
				
			}
			/*printf("\n%s턴\n", rule);
			printf("%c출력\n", 'U');
			printPhase(cube.U);
			printf("%c출력\n", 'F');
			printPhase(cube.F);
			printf("%c출력\n", 'D');
			printPhase(cube.D);
			printf("%c출력\n", 'B');
			printPhase(cube.B);
			printf("%c출력\n", 'L');
			printPhase(cube.L);
			printf("%c출력\n", 'R');
			printPhase(cube.R);*/
				
		}
		printPhase(cube.U);
		
		cube.U.clear();
		
		cube.D.clear();
		
		cube.F.clear();
		
		cube.B.clear();

		cube.L.clear();

		cube.R.clear();
	}
}
void printPhase(vector<vector<char>>&phase) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", phase[i][j]);
		}
		printf("\n");
	}
}
void Turn(char p) {
	switch (p) {
	case 'U':
		turn_clockwise(cube.L, 1);
		turn_clockwise(cube.R, 3);
		turn_phase(cube.U, cube.B, cube.F, cube.L, cube.R);//회전함수()
		turn_clockwise(cube.L, 3);
		turn_clockwise(cube.R, 1);
		break;
	case 'D':
		turn_clockwise(cube.L, 3);
		turn_clockwise(cube.R, 1);
		turn_phase(cube.D, cube.F, cube.B, cube.L, cube.R);//회전함수()
		turn_clockwise(cube.L, 1);
		turn_clockwise(cube.R, 3);
		break;
	case 'F':
		turn_phase(cube.F, cube.U, cube.D, cube.L, cube.R);//회전함수()
		break;
	case 'B':
		turn_clockwise(cube.L, 2);
		turn_clockwise(cube.R, 2);
		turn_phase(cube.B, cube.D, cube.U, cube.L, cube.R);//회전함수()
		turn_clockwise(cube.L, 2);
		turn_clockwise(cube.R, 2);
		break;
	case 'L':
		turn_clockwise(cube.U, 3);
		turn_clockwise(cube.B, 2);
		turn_clockwise(cube.D, 1);
		turn_phase(cube.L, cube.U, cube.D, cube.B, cube.F);//회전함수()
		turn_clockwise(cube.U, 1);
		turn_clockwise(cube.B, 2);
		turn_clockwise(cube.D, 3);
		break;
	case 'R':
		turn_clockwise(cube.U, 1);
		turn_clockwise(cube.B, 2);
		turn_clockwise(cube.D, 3);
		turn_phase(cube.R, cube.U, cube.D, cube.F, cube.B);//회전함수()
		turn_clockwise(cube.U, 3);
		turn_clockwise(cube.B, 2);
		turn_clockwise(cube.D, 1);
		break;
	}
}
void turn_clockwise(vector<vector<char>>&phase,int num)
{
	while (num--) {
		char temp = phase[0][0];
		phase[0][0] = phase[2][0];
		phase[2][0] = phase[2][2];
		phase[2][2] = phase[0][2];
		phase[0][2] = temp;

		temp = phase[0][1];
		phase[0][1] = phase[1][0];
		phase[1][0] = phase[2][1];
		phase[2][1] = phase[1][2];
		phase[1][2] = temp;
	}
	return;
}

void turn_phase(vector<vector<char>>&phase, vector<vector<char>>&up, vector<vector<char>>&down, vector<vector<char>>&left, vector<vector<char>>&right) {
	char temp[3];
	turn_clockwise(phase,1);
	for (int i = 0; i < 3; i++)
		temp[i] = right[i][0];
	for (int i = 0; i < 3; i++)
		right[i][0] = up[2][i];
	for (int i = 0; i < 3; i++)
		up[2][i] = left[2 - i][2];
	for (int i = 0; i < 3; i++)
		left[2-i][2] = down[0][2-i];
	for (int i = 0; i < 3; i++)
		down[0][2 - i] = temp[i];
}