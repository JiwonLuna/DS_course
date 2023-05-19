#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

int n = 6;

typedef struct{
	int dir
}element;



typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

typedef struct pos {
	int x, y;
} Position;

int offset[4][2] = {	{-1,0},		// North
						{0,1},		// East
						{1,0},		// South
						{0,-1} };	// West

Position move_to(Position pos, int dir) {
	Position next;
	next.x = pos.x + offset[dir][0];
	next.y = pos.y + offset[dir][1];
	return next;
}

bool movable(Position pos, int dir) {
	if()
}

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

// 스택 초기화 함수
void init(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(StackType* s, int item)
{
	if (is_full(s)) {
		fprintf(stderr, "stack overflow\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// 삭제 함수
int pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "stack underflow\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// 피크 함수
int peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "stack underflow \n");
		exit(1);
	}
	else return s->data[s->top];
}


int main() {

	StackType s;
	init(&s);
	Position cur;
	cur.x = 0;
	cur.y = 0;

	int init_dir = 0;

	while (1) {
		maze[cur.x][cur.y] = VISITED;
		if (cur.x == n - 1 && cur.y = n - 1) {
			printf("Found the path.\n");
			break;
		}

		bool forwarded = false;
		for (int dir = init_dir; dir < 4; dir++) {
			if (movable(cur, dir)) {
				push(&s, dir);
				cur = move_to(cur, dir);
				forwarded = true;
				init_dir = 0;
				break;

			}
		}

		if (!forwarded) {
			maze[cur.x][cur.y] = BACKTRACKED;
			if (is_empty(&s)) {
				printf("No path exists.\n");
				break;
			}

			int d = pop(&s);
			cur = move_to(cur, (d + 2) % 4);

			init_dir = d + 1;
		}
	}
	print_maze();
}