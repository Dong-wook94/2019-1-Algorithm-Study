#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
#define Start 5
#define INFI 1000000000
typedef struct Path {
	int x;
	int y;
}Path;

Path *path;
int **touch;
char **map;
int **length;
int num_size;
int near_x, near_y, min;
void set_matrix(FILE *f);
void init_matrix();
void set_map(FILE *f);
void find_route();
int path_order();
void print_output(FILE *f, int n_path);

int main(void) {
	FILE *f_in;
	FILE *f_out;
	char input_n[100];
	errno_t err_in;
	errno_t err_out;
	int num_path;

	printf("input file name?");
	gets_s(input_n, sizeof(input_n));
	err_in = fopen_s(&f_in, input_n, "r");
	set_matrix(f_in);
	fclose(f_in);

	find_route();

	err_out = fopen_s(&f_out, "output.txt", "w");
	num_path = path_order();
	print_output(f_out, num_path);
	fclose(f_out);
	return 0;
}


void set_matrix(FILE *f) {
	int i;
	fscanf_s(f, "%d ", &num_size);
	map = (char **)malloc(sizeof(char*)*(num_size + 2));
	touch = (int **)malloc(sizeof(int*)*(num_size + 2));
	length = (int **)malloc(sizeof(int*)*(num_size + 2));
	for (i = 0; i <= num_size + 1; i++) {
		map[i] = (char*)malloc(sizeof(char)*(num_size + 2));
		touch[i] = (int*)malloc(sizeof(int)*(num_size + 2));
		length[i] = (int*)malloc(sizeof(int)*(num_size + 2));
	}
		
	path = (Path *)malloc(sizeof(Path)*num_size*num_size);
	//i = 1;
	//get_input(f);
	set_map(f);
	init_matrix();

}
void init_matrix() {
	int i, j;
	for (i = 1; i <= num_size; i++)
		for (j = 1; j <= num_size; j++) {
			touch[i][j] = 0;
			length[i][j] = INFI;
		}
			
	for (i = 0; i <= num_size + 1; i++) {
		length[0][i] = -1;
		length[i][0] = -1;
		length[num_size + 1][i] = -1;
		length[i][num_size + 1] = -1;
	}
}

void set_map(FILE *f) {
	int i, j;

	for (i = 1; i <= num_size; i++) {
		for (j = 1; j <= num_size; j++) {
			fscanf_s(f, "%c", &map[i][j],sizeof(map[i][j]));
			//printf("%c ", map[i][j]);
		}
		fscanf_s(f, "%c", &map[i][num_size + 1],sizeof(map[i][num_size + 1]));
		//printf("\n");
	}

}

void find_route() {
	int i, j;

	near_x = 1;
	near_y = 1;
	length[1][1] = 0;
	touch[1][1] = Start;
	while (1/*near_x!=num_size||near_y!=num_size*/) {
		if (map[near_x + 1][near_y] == '1' && length[near_x + 1][near_y] == INFI) {//아래확인
			length[near_x + 1][near_y] = length[near_x][near_y];
			touch[near_x + 1][near_y] = UP;
		}
		else if (map[near_x + 1][near_y] == '0' && length[near_x + 1][near_y] == INFI) {
			length[near_x + 1][near_y] = length[near_x][near_y] + 1;
			touch[near_x + 1][near_y] = UP;
		}


		if (map[near_x - 1][near_y] == '1' && length[near_x - 1][near_y] == INFI) {//위확인
			length[near_x - 1][near_y] = length[near_x][near_y];
			touch[near_x - 1][near_y] = DOWN;
		}
		else if (map[near_x - 1][near_y] == '0' && length[near_x - 1][near_y] == INFI) {
			length[near_x - 1][near_y] = length[near_x][near_y] + 1;
			touch[near_x - 1][near_y] = DOWN;
		}

		if (map[near_x][near_y - 1] == '1' && length[near_x][near_y - 1] == INFI) {//좌확인
			length[near_x][near_y - 1] = length[near_x][near_y];
			touch[near_x][near_y - 1] = RIGHT;
		}
		else if (map[near_x][near_y - 1] == '0' && length[near_x][near_y - 1] == INFI) {
			length[near_x][near_y - 1] = length[near_x][near_y] + 1;
			touch[near_x][near_y - 1] = RIGHT;
		}

		if (map[near_x][near_y + 1] == '1' && length[near_x][near_y + 1] == INFI) {//우확인
			length[near_x][near_y + 1] = length[near_x][near_y];
			touch[near_x][near_y + 1] = LEFT;
		}
		else if (map[near_x][near_y + 1] == '0' && length[near_x][near_y + 1] == INFI) {
			length[near_x][near_y + 1] = length[near_x][near_y] + 1;
			touch[near_x][near_y + 1] = LEFT;
		}
		//사방확인했고 min값찾고 원래있던 near -1 처리 해줘야됨.w
		length[near_x][near_y] = -1;

		if (touch[num_size][num_size] != 0)
			break;
		min = INFI;
		for (i = 1; i <= num_size; i++) {
			for (j = 1; j <= num_size; j++) {
				if (min > length[i][j] && length[i][j] != -1) {
					min = length[i][j];
					near_x = i;
					near_y = j;
				}
			}
		}
		//printf("\n%d %d",near_x,near_y);
	}
	near_x = num_size;
	near_y = num_size;


}

int path_order() {
	int i = 0;
	while (1) {
		path[i].x = near_x;
		path[i].y = near_y;
		if (touch[near_x][near_y] == Start)
			return i;

		if (touch[near_x][near_y] == UP)
			near_x = near_x - 1;
		else if (touch[near_x][near_y] == DOWN)
			near_x = near_x + 1;
		else if (touch[near_x][near_y] == LEFT)
			near_y = near_y - 1;
		else if (touch[near_x][near_y] == RIGHT)
			near_y = near_y + 1;


		if (near_x < 1 || near_y < 1) {
			//printf("map밖");
			return 0;
		}
		i++;
	}
}

void print_output(FILE *f, int n_path) {
	int i, j;
	
	//printf("\nlength\n");
	for (i = 1; i <= num_size; i++) {
		for (j = 1; j <= num_size; j++) {
			//printf("%10d ", length[i][j]);
		}
		//printf("\n");
	}

	//printf("\ntouch\n");
	for (i = 1; i <= num_size; i++) {
		for (j = 1; j <= num_size; j++) {
			//printf("%d ", touch[i][j]);
		}
		//printf("\n");
	}
	for (i = 0; i <= num_size + 1; i++) {
		free(map[i]);
		free(touch[i]);
		free(length[i]);
	}
	free(map);
	free(touch);
	free(length);
	//printf("벽깨는 횟수 : ");
	//printf("%d\n", min);
	fprintf_s(f, "%d\n", min);
	for (i = n_path; i >= 0; i--) {
		//printf("%d %d\n", path[i].x, path[i].y);
		fprintf_s(f, "%d %d\n", path[i].x, path[i].y);
	}
	free(path);
}