//用于VS解决不安全函数的警告
#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//产生随机数
int get_random_num(int m, int n)
{
	return rand()%(n-m+1)+m;
}

//设置雷阵
void set_mine(char mine[ROWS+2][COLS+2], int row, int col)
{
	int count = DEFAULT_COUNT;

	while(count)//雷的个数
	{
		int x = get_random_num(1, 10);
		int y = get_random_num(1, 10);
		if(mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//打印雷阵（排雷结果）信息
void display(char board[ROWS+2][COLS+2], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("    ");
	for(i=1; i<=10; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for(i=1; i<=10; i++)
	{
		printf("---");
	}
	printf("\n");
	for(i=1; i<row-1; i++)
	{
		printf("%2d| ", i);
		for(j=1; j<col-1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}


//统计非雷区周围的雷的个数
int  get_mine_count(char board[ROWS+2][COLS+2], int x, int y)
{
	return (board[x-1][y-1]-'0')+
		(board[x][y-1]-'0')+
		(board[x+1][y-1]-'0')+
		(board[x+1][y]-'0')+
		(board[x+1][y+1]-'0')+
		(board[x][y+1]-'0')+
		(board[x-1][y+1]-'0')+
		(board[x-1][y-1]-'0');
}

//游戏的主逻辑
void play_game(char mine[ROWS+2][COLS+2], char show[ROWS+2][COLS+2])
{
	while(1)
	{
		int x = 0;
		int y = 0;
		int win = 0;
		printf("请输入坐标>:");
		scanf("%d%d", &x, &y);
		if(((x>=1)&&(x<=10))&&((y>=1)&&(y<=10)))
		{
			if(mine[x][y] == '1')
			{
				printf("被炸死\n");
				display(mine, ROWS+2, COLS+2);
				break;
			}
			else
			{
				int ret = 0;
				win++;
				ret = get_mine_count(mine, x, y);
				show[x][y] = ret+'0';
				display(show, ROWS+2, COLS+2);
				if(win == COLS*ROWS-DEFAULT_COUNT)
				{
					printf("雷排完了\n");
					display(mine, ROWS+2, COLS+2);
					break;
				}
			}
		}
		else
		{
			printf("坐标输入有误\n");	
		}
	}
}
