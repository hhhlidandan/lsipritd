#include "game.h"

int main()
{
	
	int quit = 0;
	int n = 0;
	while (!quit)
	{
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			Game();
			break;//��Ϸ���������ܼ����棬����switch��䣬�ٴ�ѡ���Ƿ�Ҫ��
		case 2:
			quit = 1;//�´ν�ѭ����� ��1Ϊ�٣���ֱ���˳���
			break;
		default:
			printf("������������������>\n");
			continue;
		}
	}
	printf("Bye bye ��ӭ�´�����\n");
	system("pause");
	return 0;
}