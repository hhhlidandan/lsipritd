#include<stdio.h>                                                                  
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	    pid_t id = fork();
	    if (id == 0)
		     {//child
		
			         int count = 5;
		        while (count--)
			        {
			        printf("I am child:pid:%d,ppid:%d\n", getpid(), getppid());
			        sleep(1);
			        }
		        exit(3);
		    }
	    else
		    {//father
		        int status = 0;
		        printf("I am father:pid:%d,ppid:%d\n", getpid(), getppid());
		       pid_t ret = waitpid(id, &status, WNOHANG);//非阻塞方式
			   pid_t ret = waitpid(id, &status, WNOHANG);//非阻塞方式
			         if (ret>0)
				         {
				          printf("wait success,ret:%d\n", ret);
				           if (WIFEXITED(status))
					           {
					            printf("code:%d", WEXITSTATUS(status));
					          }
				           else
					           {
					               printf("exit error\n");
					           }
				        }
			          if (ret == 0)
				           {
				               printf("father is doing otherthing\n");
				          }
			           else
				           {
				              printf("wait failed\n");
				          }
				}
			 return 0;

		}