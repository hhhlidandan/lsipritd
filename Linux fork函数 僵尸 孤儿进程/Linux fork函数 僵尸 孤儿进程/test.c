//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>
//int main()
//{
//	int ret = fork();
//	if (ret<0)//����ʧ�ܣ�����-1
//	{
//		perror("fork");
//		return -1;
//	}
//	else if (ret == 0)//������ͬʱִ�е�
//	{//child�ӽ���
//		printf("I am child: %d!,ret:%d\n", getpid(), ret);//�ӽ��̷���0
//	}
//	else
//	{//father������
//		printf("I am father: %d!,ret:%d\n", getpid(), ret);//�����̷����ӽ��̵�pid
//	}
//	sleep(1);
//	return 0;
//}


#include<stdio.h>                                                                  
#include<unistd.h>
#include<stdlib.h>

//int main()
//{
//	pid_t id = fork();//����һ������
//	if (id<0)
//	{
//		perror("fork");
//		return 1;
//	}
//	else if (id == 0)
//	{//child//�ӽ������˳�
//		while (1)
//		{
//			printf("I am child:pid:%d!,ppid:%d\n", getpid(), getppid());
//			sleep(5);//5΢����ӽ����˳�
//			exit(EXIT_SUCCESS);//�����˳�������exit()����
//		}
//	}
//	else{
//		while (1)
//		{
//			//father�ø�����һֱִ��
//			printf("I am father:pid:%d!,p//pid:%d\n", getpid(), getppid());
//			sleep(20);//ÿ��20���ӡһ�κ�ΪZ״̬
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
//	{//child�ӽ���
//		while (1)
//		{
//			printf("I am child:pid:%d!,ppid:%d\n", getpid(), getppid());
//			sleep(10)��//10��֮��ΪR״̬
//		}
//	}
//	else{
//		while (1)
//		{
//			//father
//			printf("I am father:pid:%d!,p//pid:%d\n", getpid(), getppid());
//			sleep(5); 5��֮���˳�
//				exit(EXIT_SUCCESS);//�����˳�������exit()����
//		}
//	}
//	return 0;
//}

