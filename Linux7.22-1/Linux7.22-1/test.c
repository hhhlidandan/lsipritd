#include<stdio.h>                                                                  
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
     pid_t id = fork();
     if (id == 0)
	{//child
		int count = 5;
		while (count--)
	    {
		 printf("I am child,pid:%d,ppid:%d\n", getpid(), getppid());
		 sleep(1);
		 }
		 exit(20);
	}
	 else
	{//father
	 printf("I am father,pid:%d,ppid:%d\n", getpid(), getppid());
	 int status = 0;
	 while (1)
	 {
	   pid_t ret = waitpid(id, &status, WNOHANG);
	   if (ret>0)
	   {
		  printf("wait success,ret:%d\n", ret);
		  if (WIFEXITED(status))
		  {
		    printf("code:%d\n", WEXITSTATUS(status));
		  }
		  else
		  {
		   printf("exit error\n");
		   }
	       break;
	   }
	  if (ret == 0)
	  {
		 printf("child is run,father do otherthing\n");
		 printf("wait again...\n");
	   }
	  else
	 {
	   printf("wait faild\n");
	   break;
	  }
    }
  }
   return 0;
}