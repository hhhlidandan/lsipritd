//�����в���
#include<stdio.h>
int main(int argc, char *argv[], char *env[])//argc,*argv[]Ϊ�����в�����*env[]Ϊ��������
{
	int i = 0;
	for (; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}

	return 0;
}
//ͨ������������environ��ȡ
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
//*ͨ��ϵͳ���û�ȡ�����û�������
#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("%s\n", getenv("PATH"));
	return 0;
}


//���̴���
#include<stdio.h>                                                                  
#include<unistd.h>
void exit(int ststus);
int main()
{
	printf("hello!"); //printf���������������
	sleep(3);
	exit(0);
}

