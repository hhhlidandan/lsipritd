#include "game.h"

//判断棋盘有无空位置
static int Isfull(char board[ROW][COL], int row, int col)//不对外显示，用static修饰
{
	int i = 0;
	
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;	
}

//猜数字决定玩家和电脑谁先走
static int Guess(char board[ROW][COL],int row,int col)//不对外显示，用static修饰
{
	while (1)
	{
		int number = 0;
		int x = rand() % 2;//生成0~1的随机数
		printf("请输入正反面< 0:正面, 1:反面 >:");
		scanf("%d", &number);
		if (x == number)
		{
			printf("你猜对了，你先走\n");
			return 1;
		}
		else
		{
			printf("你猜错了，电脑先走\n");
			Sleep(1000);
			return 2;
		}
	}
}

//打印菜单
void menu()
{
	printf("********************************\n");
	printf("*******欢迎来到三子棋游戏*******\n");
	printf("********************************\n");
	printf("*****   1.Play    2.Exit   *****\n");
	printf("********************************\n");
}

//对棋盘初始化，都为空
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			board[i][j] = INIT;
		}
		printf("\n");
	}
}

//显示棋盘
void Showboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	printf("    1 | 2 | 3 \n");
	printf("--------------\n");
	for (; i < row; i++)
	{ 
		int j = 0;
		printf("%d |", i+1);
		for (; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		printf("--------------\n");
	}
}

//判断输赢  //判断输赢 'X':玩家赢，'O':电脑赢 'F':平局  'N':继续下棋
char Judge(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//对玩家和电脑落子是否可以赢的判断
	for (; i < row; i++)
	{
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' '){
			return board[i][0];
		}
	}
	for (; j < col; j++)
	{
		if (board[0][j] == board[1][j] && \
			board[1][j] == board[2][j] && \
			board[0][j] != ' '
			){
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && \
		board[1][1] == board[2][2] &&\
		board[1][1] != ' '){
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[1][1] != ' '){
		return board[1][1];
	}
	////////////////////////////////////////
	if (Isfull(board, row, col))
	{
		return 'F';//满了返回'F'平局
	}
	return 'N';//否则继续落子
}

//电脑落子
void Computermove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y]= C_CLR;
			break;
		}
	}
	printf("电脑走完，该你了\n");
}


//###############游戏整体实现部分##################
void Game()
{
	char board[ROW][COL];
	Initboard(board,ROW,COL);
	srand((unsigned long)time(NULL));
	int x = 0;
	int y = 0;	
	char win = ' ';//默认为空
	int input = 0;
	int step = Guess(board, ROW, COL);//  1 让player先走，2 让电脑先走
	Showboard(board, ROW, COL);
	do
	{
		switch (step)
		{
		case 1:
		{
				  while (1)
				  {
					  printf("######################\n");
					  printf("请输入你落子位置<x,y>#\n");
					  scanf("%d %d", &x, &y);
					  if (x<1 || x>3 || y<1 || y>3)
					  {
						  printf("你输入的位置有误，请重新输入\n");
						  continue;
					  }
					  if (board[x - 1][y - 1] != ' ')
					  {
						  printf("你输入的位置已被占，请重新输入\n");
						  continue;
					  }
					  board[x - 1][y - 1] = P_CLR;
					  Showboard(board, ROW, COL);
					  printf("你走完了，等等电脑\n");
					  Sleep(1000);
					  break;
				  }
				  step = 2;
		}	
			break;
		case 2:
		{
				  printf("######################\n");
				  Computermove(board, ROW, COL);
				  Showboard(board, ROW, COL);
				  step = 1;
				  break;
		}	
		default:
			break;
		}
		//判断输赢 'X':玩家赢，'O':电脑赢 'F':平局  'N':继续下棋
		win = Judge(board, ROW, COL);//'X' '0' 'F' 'N'
		if (win != 'N')
		{
			break;
		}
	} while (1);

	if (win == P_CLR)
	{
		printf("恭喜你，你赢了\n");
	}
	else if (win == C_CLR)
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}	
}