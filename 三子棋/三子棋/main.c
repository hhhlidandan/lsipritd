#include "game.h"

int main()
{
	
	int quit = 0;
	int n = 0;
	while (!quit)
	{
		menu();
		printf("请选择>\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			Game();
			break;//游戏结束还可能继续玩，跳出switch语句，再次选择是否要玩
		case 2:
			quit = 1;//下次进循环检测 ！1为假，就直接退出了
			break;
		default:
			printf("输入有误，请重新输入>\n");
			continue;
		}
	}
	printf("Bye bye 欢迎下次再来\n");
	system("pause");
	return 0;
}