/*This program prints a series of numbers starting with loop 1, then loop 2 and then loop 3 till the limit is reached*/

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mysemaphore;

int threadnumber=1;
int limit;

/*Thread Function 1*/
void *threadFunc1(void *args)
{
    int loop_index=1;

    sem_wait(&mysemaphore);

    while(loop_index<=limit)
    {
        if(threadnumber == 1)
        {
            printf("%d, ",loop_index);
            loop_index+=3;
            threadnumber++;
        }
        else
        {
           sem_post(&mysemaphore); 
        }
       
    }
    
}
/*Thread Function 2*/
void *threadFunc2(void *args)
{
    
    int loop_index=2;

    sem_wait(&mysemaphore);

    while(loop_index<=limit)
    {
        if(threadnumber == 2)
        {
            printf("%d, ",loop_index);
            loop_index+=3;
            threadnumber++;
        }
        else
        {
           sem_post(&mysemaphore); 
        }
       
    }
    
}
/*Thread Function 3*/
void *threadFunc3(void *args)
{
    
    int loop_index=3;

    sem_wait(&mysemaphore);

    while(loop_index<=limit)
    {
        if(threadnumber == 3)
        {
            printf("%d, ",loop_index);
            loop_index+=3;
            threadnumber-=2;
        }
        else
        {
           sem_post(&mysemaphore); 
        }
       
    }
    
}

/*Main Function*/

int main()
{
    	pthread_t mythread1;
	pthread_t mythread2;
	pthread_t mythread3;
	
	printf("\nEnter the limit upto which you want to print: ");
	scanf("%d",&limit);

	printf("\n");

	sem_init(&mysemaphore,0,1);
	
	/*Threads Creation*/
	pthread_create(&mythread1,NULL,&threadFunc1,NULL);
	pthread_create(&mythread2,NULL,&threadFunc2,NULL);
	pthread_create(&mythread3,NULL,&threadFunc3,NULL);	

	/*Thread Join*/
	pthread_join(mythread1,NULL);
	pthread_join(mythread2,NULL);
	pthread_join(mythread3,NULL);

	printf("\n\n");

	sem_destroy(&mysemaphore);
    	return 0;
}
