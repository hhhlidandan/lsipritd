//命令行参数
#include<stdio.h>
int main(int argc, char *argv[], char *env[])//argc,*argv[]为命令行参数，*env[]为环境变量
{
	int i = 0;
	for (; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}

	return 0;
}
//通过第三方变量environ获取
#include<stdio.h>
int main(int argc, char *argv[])
{
	extern char **environ;
	int i = 0;
	for (; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return 0;
}
//*通过系统调用获取或设置环境变量
#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("%s\n", getenv("PATH"));
	return 0;
}


//进程创建
#include<stdio.h>                                                                  
#include<unistd.h>
void exit(int ststus);
int main()
{
	printf("hello!"); //printf函数有输出缓冲区
	sleep(3);
	exit(0);
}

