#include "game.h"

//�ж��������޿�λ��
static int Isfull(char board[ROW][COL], int row, int col)//��������ʾ����static����
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

//�����־�����Һ͵���˭����
static int Guess(char board[ROW][COL],int row,int col)//��������ʾ����static����
{
	while (1)
	{
		int number = 0;
		int x = rand() % 2;//����0~1�������
		printf("������������< 0:����, 1:���� >:");
		scanf("%d", &number);
		if (x == number)
		{
			printf("��¶��ˣ�������\n");
			return 1;
		}
		else
		{
			printf("��´��ˣ���������\n");
			Sleep(1000);
			return 2;
		}
	}
}

//��ӡ�˵�
void menu()
{
	printf("********************************\n");
	printf("*******��ӭ������������Ϸ*******\n");
	printf("********************************\n");
	printf("*****   1.Play    2.Exit   *****\n");
	printf("********************************\n");
}

//�����̳�ʼ������Ϊ��
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

//��ʾ����
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

//�ж���Ӯ  //�ж���Ӯ 'X':���Ӯ��'O':����Ӯ 'F':ƽ��  'N':��������
char Judge(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//����Һ͵��������Ƿ����Ӯ���ж�
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
		return 'F';//���˷���'F'ƽ��
	}
	return 'N';//�����������
}

//��������
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
	printf("�������꣬������\n");
}


//###############��Ϸ����ʵ�ֲ���##################
void Game()
{
	char board[ROW][COL];
	Initboard(board,ROW,COL);
	srand((unsigned long)time(NULL));
	int x = 0;
	int y = 0;	
	char win = ' ';//Ĭ��Ϊ��
	int input = 0;
	int step = Guess(board, ROW, COL);//  1 ��player���ߣ�2 �õ�������
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
					  printf("������������λ��<x,y>#\n");
					  scanf("%d %d", &x, &y);
					  if (x<1 || x>3 || y<1 || y>3)
					  {
						  printf("�������λ����������������\n");
						  continue;
					  }
					  if (board[x - 1][y - 1] != ' ')
					  {
						  printf("�������λ���ѱ�ռ������������\n");
						  continue;
					  }
					  board[x - 1][y - 1] = P_CLR;
					  Showboard(board, ROW, COL);
					  printf("�������ˣ��ȵȵ���\n");
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
		//�ж���Ӯ 'X':���Ӯ��'O':����Ӯ 'F':ƽ��  'N':��������
		win = Judge(board, ROW, COL);//'X' '0' 'F' 'N'
		if (win != 'N')
		{
			break;
		}
	} while (1);

	if (win == P_CLR)
	{
		printf("��ϲ�㣬��Ӯ��\n");
	}
	else if (win == C_CLR)
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}	
}