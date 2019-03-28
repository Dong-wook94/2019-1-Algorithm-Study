#include<stdio.h>
#include<vector>
using namespace std;

vector<vector<char>> U;
vector<vector<char>> D;
vector<vector<char>> F;
vector<vector<char>> B;
vector<vector<char>> L;
vector<vector<char>> R;
char rule[2];
void Turn(char p);//한번돌릴때
void turn_clockwise(vector<vector<char>>&phase, int num);//시계방향회전
void turn_phase(vector<vector<char>>&phase, vector<vector<char>>&up, vector<vector<char>>&down, vector<vector<char>>&left, vector<vector<char>>&right);//회전할때 그면,위아래좌우
void printPhase(vector<vector<char>>&phase);
int main() {
	int T;
	int num_turn;
	int dir;
	scanf("%d", &T);


	while (T--)
	{
		U = vector<vector<char>>(3, vector<char>(3, 'w'));
		D = vector<vector<char>>(3, vector<char>(3, 'y'));
		F = vector<vector<char>>(3, vector<char>(3, 'r'));
		B = vector<vector<char>>(3, vector<char>(3, 'o'));
		L = vector<vector<char>>(3, vector<char>(3, 'g'));
		R = vector<vector<char>>(3, vector<char>(3, 'b'));
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
		}
		printPhase(U);
		U.clear();
		D.clear();
		F.clear();
		B.clear();
		L.clear();
		R.clear();
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
		turn_clockwise(L, 1);
		turn_clockwise(R, 3);
		turn_phase(U, B, F, L, R);//회전함수()
		turn_clockwise(L, 3);
		turn_clockwise(R, 1);
		break;
	case 'D':
		turn_clockwise(L, 3);
		turn_clockwise(R, 1);
		turn_phase(D, F, B, L, R);//회전함수()
		turn_clockwise(L, 1);
		turn_clockwise(R, 3);
		break;
	case 'F':
		turn_phase(F, U, D, L, R);//회전함수()
		break;
	case 'B':
		turn_clockwise(L, 2);
		turn_clockwise(R, 2);
		turn_phase(B, D, U, L, R);//회전함수()
		turn_clockwise(L, 2);
		turn_clockwise(R, 2);
		break;
	case 'L':
		turn_clockwise(U, 3);
		turn_clockwise(B, 2);
		turn_clockwise(D, 1);
		turn_phase(L, U, D, B, F);//회전함수()
		turn_clockwise(U, 1);
		turn_clockwise(B, 2);
		turn_clockwise(D, 3);
		break;
	case 'R':
		turn_clockwise(U, 1);
		turn_clockwise(B, 2);
		turn_clockwise(D, 3);
		turn_phase(R, U, D, F, B);//회전함수()
		turn_clockwise(U, 3);
		turn_clockwise(B, 2);
		turn_clockwise(D, 1);
		break;
	}
}
void turn_clockwise(vector<vector<char>>&phase, int num)
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
	turn_clockwise(phase, 1);
	for (int i = 0; i < 3; i++)
		temp[i] = right[i][0];
	for (int i = 0; i < 3; i++)
		right[i][0] = up[2][i];
	for (int i = 0; i < 3; i++)
		up[2][i] = left[2 - i][2];
	for (int i = 0; i < 3; i++)
		left[2 - i][2] = down[0][2 - i];
	for (int i = 0; i < 3; i++)
		down[0][2 - i] = temp[i];
}