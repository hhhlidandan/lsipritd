//#include<stdio.h>
//#include<string.h>
//#include<unistd.h>
//int main()
//{
//	int i = 0;
//	char bar[102];
//	memset(bar, '\0', sizeof(bar));
//	const char *lable = "|/-\\";//添加一个标签，按顺时针输出
//	for (; i <= 100; i++)
//	{
//		bar[i] = '*';
//		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i % 4]);  //  - 左对齐， %%输出%                                                                                                                        
//		fflush(stdout);//输出缓冲区
//		usleep(100000);//挂起一段时间
//	}
//	printf("\n");
//}
