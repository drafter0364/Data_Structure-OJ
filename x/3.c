//3-maze_key.c
#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define MAXLEN 25
#define MAXPATH 50
typedef int Status;
typedef struct { //迷宫的坐标
    int r, c; //r 表示行，c表示列
}PosType;
char maze[MAXLEN][MAXLEN];
char maze_origin[MAXLEN][MAXLEN];
PosType path[MAXPATH];
int count = 0;
int main()
{
    int row, col;
    scanf("%d %d\n", &row, &col);
    int i, j;
    PosType start, end, key;
    //读入迷宫
    for (i = 1; i < row + 1; i++) {
        for (j = 1; j < col + 1; j++)
        {
            scanf("%c", &maze_origin[i][j]);
            if (maze_origin[i][j] == 'R') {
                start.c = j;
                start.r = i;
            }
            else if (maze_origin[i][j] == 'Y') {
                key.c = j;
                key.r = i;
            }
            else if (maze_origin[i][j] == 'C') {
                end.c = j;
                end.r = i;
            }
        }
        getchar();
    }
    //建围墙
    for (i = 0; i < row + 2; i++)
        maze_origin[i][0] = '1';
    for (i = 0; i < row + 2; i++)
        maze_origin[i][col + 1] = '1';
    for (j = 1; j < col + 2; j++)
        maze_origin[0][j] = '1';
    for (j = 1; j < col + 2; j++)
        maze_origin[row + 1][j] = '1';
    //放入操作迷宫
    memcpy(maze, maze_origin, MAXLEN * MAXLEN * sizeof(char));
    SeekPath(key, end);
    memcpy(maze, maze_origin, MAXLEN * MAXLEN * sizeof(char));
    SeekPath(start, key);
    printf("%d %d\n", start.r, start.c);
    while (count--)
    {
        printf("%d %d\n", path[count].r, path[count].c);
    }
    
    return 0;
}

//在迷宫的当前位置留下走过标记(*)
void FootPrint(PosType CurPos) {
    maze[CurPos.r][CurPos.c] = '*';
}

//在迷宫的当前位置留下走不通标记(!)
void MarkPrint(PosType CurPos) {
    maze[CurPos.r][CurPos.c] = '!';
}
PosType NextPos(PosType CurPos, int Dir) {
    PosType ReturnPos;
    switch (Dir) {
    case 2: ReturnPos.r = CurPos.r; ReturnPos.c = CurPos.c + 1; break;
    case 1: ReturnPos.r = CurPos.r + 1; ReturnPos.c = CurPos.c; break;
    case 4: ReturnPos.r = CurPos.r; ReturnPos.c = CurPos.c - 1; break;
    case 3: ReturnPos.r = CurPos.r - 1; ReturnPos.c = CurPos.c; break;
    }
    return ReturnPos;
}
Status Pass(PosType CurPos) {
    if (maze[CurPos.r][CurPos.c] == '0' || maze[CurPos.r][CurPos.c] == 'Y' || maze[CurPos.r][CurPos.c] == 'C')
        return OK; // 如果当前位置是空格，则可以通过
    else return ERROR;//可能是墙，可能已经走过：包括当前的路径和被标记为走不通的通道块
}
Status SeekPath(PosType curPos, PosType endPoint) {
    //从迷宫中坐标点curPos的位置寻找通向终点end1的路径
    //若找到则返回OK，否则返回ERROR
    int i;
    PosType pos;
    if ((curPos.r == endPoint.r) && (curPos.c == endPoint.c))
        return  OK;
    for (i = 0; i < 4; i++) {
        pos = NextPos(curPos, i + 1);
        if (Pass(pos)) {
            FootPrint(pos); // 留下足迹
            if (SeekPath(pos, endPoint)) {
                path[count++] = pos;
                maze[pos.r][pos.c] = '+'; //记录路径
                return OK;
            }
        }
    } //for
    return ERROR;
}