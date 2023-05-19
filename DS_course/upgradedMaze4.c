#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAZE_SIZE 10

typedef struct Mouse
{
    int x;
    int y;
}Mouse;

typedef struct Stack
{
    Mouse data[MAX_SIZE];
    int top;
}Stack;

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1','1','1','1','1'},
    {'m','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','1','0','0','1','0','1'},
    {'1','0','1','1','1','0','0','1','0','1'},
    {'1','0','0','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','0','0','0','1','0','X'},
    {'1','1','1','1','1','1','1','1','1','1'} };

char direction[4] = { 'N', 'E', 'S', 'W' };

void init(Stack* p)
{
    p->top = -1;
}

int is_full(Stack* p)
{
    return (p->top == MAX_SIZE - 1);
}

int is_empty(Stack* p)
{
    return (p->top == -1);
}

void push(Stack* p, Mouse data)
{
    if (is_full(p))
    {
        fprintf(stderr, "스택이 꽉찼습니다\n");
        return;
    }
    else
    {
        p->top++;
        p->data[p->top].x = data.x;
        p->data[p->top].y = data.y;
    }
}

Mouse pop(Stack* p)
{
    if (is_empty(p))
    {
        fprintf(stderr, "스택이 비어있습니다\n");
        exit(1);
    }

    return p->data[(p->top)--];
}

Mouse peek(Stack* p)
{
    if (is_empty(p))
    {
        fprintf(stderr, "스택이 비어있습니다\n");
        exit(1);
    }
    else return p->data[p->top];
}

bool forwarded = false;
void FindWay(Stack* s, int x, int y)
{
    if (x < 0 || y < 0 || x > MAZE_SIZE || y > MAZE_SIZE) return;

    if (maze[x][y] != '1' && maze[x][y] != '.')
    {
        Mouse tmp;
        tmp.x = x;
        tmp.y = y;

        push(s, tmp);

        forwarded = true;
        return;
    }

    forwarded = false;

}

bool movable(Mouse* m)
{
    int x = m->x;
    int y = m->y;

    if (x < 0 || y < 0 || x > MAZE_SIZE || y > MAZE_SIZE) return false;
    for (int t_dir = 0; t_dir < 4; t_dir++) {
        x = m->x;
        y = m->y;

        if (t_dir == 0) x--;
        else if (t_dir == 1) y++;
        else if (t_dir == 2) x++;
        else if (t_dir == 3) y--;

        if (maze[x][y] != '1' && maze[x][y] != '.')
        {
            return true;
        }
    }

    return false;


}

void print_maze(int x, int y) {
    // print maze
    //printf("미로 \n");
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == x && j == y) {
                printf("＠");
            }
            else if (maze[i][j] == '0') {
                printf("□");
            }
            else if (maze[i][j] == '1') {
                printf("■");
            }
            else if (maze[i][j] == '.') {
                printf("○");
            }
            else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    Stack s;
    Stack path_save;
    Stack path;
    Mouse m;
    Mouse m2;
    Mouse m3[MAX_SIZE];
    int n = 0, i, j, x, y ;

    init(&s);
    init(&path_save);
    init(&path);

    // 시작점 탐색
    for (i = 0; i < MAZE_SIZE; i++)
    {
        for (j = 0; j < MAZE_SIZE; j++)
        {
            if (maze[i][j] == 'm')
            {
                m.x = i;
                m.y = j;
            }
        }
    }

    print_maze(m.x, m.y);

    printf("\n이동 경로\n");
    printf("시작 (%d,%d) -> \n", m.x, m.y);

    int input;
    int dir = 0;
    while (maze[m.x][m.y] != 'X')
    {
        
        x = m.x;
        y = m.y;

        maze[x][y] = '.'; // 방문한 곳을 표시
        forwarded = false;

        if (kbhit()) {
            input = getch();
            if (input == 224) {
                input = getch();
            }
            system("cls");
            switch (input) {
            case 72:        // 북, 위쪽 방향키
                dir = 0;
                FindWay(&s, x - 1, y);
                break;

            case 77:        // 동, 오른쪽 방향키
                dir = 1;
                FindWay(&s, x, y + 1);
                break;

            case 80:        // 남, 아래쪽 방향키
                dir = 2;
                FindWay(&s, x + 1, y);
                break;

            case 75:        // 서, 왼쪽 방향키
                dir = 3;
                FindWay(&s, x, y - 1);
                break;


            }



            if (!forwarded) 
            {
                //printf("Checking...\n");
                if (movable(&m)) {
                    print_maze(m.x, m.y);
                    printf("Try other way... \n");

                }
                else {   //갈 수 있는 방향이 없다.
                    while (!movable(&m)) {
                        m = pop(&s);
                    }
                    if (is_empty(&s)) {
                        printf("No path exists.\n");
                        break;
                    }
                    push(&path_save, m);
                    n = path_save.top;
                    m3[n] = peek(&path_save);
                    print_maze(m.x, m.y);
                    printf(" ### Return to last crossroad. ### \n");
                }

            }
            else {
                m = peek(&s); // 현재 좌표를 변경
                push(&path_save, m);
                n = path_save.top;
                m3[n] = peek(&path_save);
                print_maze(m.x, m.y);


            }

            printf("input direction : %c\n", direction[dir]);
            int enter_num = 0;
            printf("시작 (1,0) -> \n");
            for (int i = 0; i < n; i++) {
                printf("(%d,%d) -> ", m3[i].x, m3[i].y);
                
                enter_num++;
                if (enter_num == 6) {
                    printf("\n");
                    enter_num = 0;
                }
                
            }
            printf("(%d,%d) -> ", m.x, m.y);
            
        }
        // 이동 가능한 곳을 탐색

    }
    printf("도착\n");
    printf("탐색 성공\n");

    return 0;
}