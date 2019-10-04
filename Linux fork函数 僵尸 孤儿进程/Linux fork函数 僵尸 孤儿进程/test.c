//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>
//int main()
//{
//	int ret = fork();
//	if (ret<0)//调用失败，返回-1
//	{
//		perror("fork");
//		return -1;
//	}
//	else if (ret == 0)//下面是同时执行的
//	{//child子进程
//		printf("I am child: %d!,ret:%d\n", getpid(), ret);//子进程返回0
//	}
//	else
//	{//father父进程
//		printf("I am father: %d!,ret:%d\n", getpid(), ret);//父进程返回子进程的pid
//	}
//	sleep(1);
//	return 0;
//}


#include<stdio.h>                                                                  
#include<unistd.h>
#include<stdlib.h>

//int main()
//{
//	pid_t id = fork();//创建一个进程
//	if (id<0)
//	{
//		perror("fork");
//		return 1;
//	}
//	else if (id == 0)
//	{//child//子进程先退出
//		while (1)
//		{
//			printf("I am child:pid:%d!,ppid:%d\n", getpid(), getppid());
//			sleep(5);//5微妙后，子进程退出
//			exit(EXIT_SUCCESS);//进程退出，调用exit()函数
//		}
//	}
//	else{
//		while (1)
//		{
//			//father让父进程一直执行
//			printf("I am father:pid:%d!,p//pid:%d\n", getpid(), getppid());
//			sleep(20);//每个20秒打印一次后为Z状态
//		}
//	}
//	return 0;
//}


#include<stdio.h>                                                                  
#include<unistd.h>
#include<stdlib.h>

//int main()
//{
//	pid_t id = fork();
//	if (id<0)
//	{
//		perror("fork");
//		return 1;
//	}
//	else if (id == 0)
//	{//child子进程
//		while (1)
//		{
//			printf("I am child:pid:%d!,ppid:%d\n", getpid(), getppid());
//			sleep(10)；//10秒之后为R状态
//		}
//	}
//	else{
//		while (1)
//		{
//			//father
//			printf("I am father:pid:%d!,p//pid:%d\n", getpid(), getppid());
//			sleep(5); 5秒之后退出
//				exit(EXIT_SUCCESS);//进程退出，调用exit()函数
//		}
//	}
//	return 0;
//}

