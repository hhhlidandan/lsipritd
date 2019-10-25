#include<stdio.h>                                                                  
#include<unistd.h>
#include<pthread.h>
void *thread_rout(void *arg)
{
	    while (1){
		    printf("I am new thread ,name is %s\n", (char*)arg);
		    sleep(1);
	
	}
}
 int main()
 {
	    pthread_t id;
	    pthread_create(&id, NULL, thread_rout, "thread 1");
	    while (1){
		    printf("I am main thread\n");
		    sleep(2);
	
	}
	    return 0;
	}
