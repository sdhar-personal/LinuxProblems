#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mymutex;
pthread_cond_t mycond;
pthread_cond_t mycond2;
pthread_cond_t mycond3;

int limit;
int done = 1;

void *myThreadFunc1(void *args)
{
    int loop_index = 1;
    pthread_mutex_lock(&mymutex);

    while(loop_index<=limit)
    {
        if(done == 1)
        {
            printf("%d, ",loop_index);
            loop_index+=3;
            done++;
            pthread_cond_signal(&mycond2);
        }
        else
        {
            pthread_cond_wait(&mycond,&mymutex);

        }
    }
    pthread_mutex_unlock(&mymutex);

    return NULL;
}

void *myThreadFunc2(void *args)
{
    int loop_index = 2;
    pthread_mutex_lock(&mymutex);

        while(loop_index<=limit)
        {

            if(done == 2)
            {
                printf("%d, ",loop_index);
                loop_index+=3;
                done++;
                pthread_cond_signal(&mycond3);
            }
            else
            {
                pthread_cond_wait(&mycond2,&mymutex);
            }

        }
    pthread_mutex_unlock(&mymutex);

    return NULL;
}

void *myThreadFunc3(void *args)
{
    int loop_index = 3;
    pthread_mutex_lock(&mymutex);

        while(loop_index<=limit)
        {

            if(done == 3)
            {
                printf("%d, ",loop_index);
                loop_index+=3;
                done-=2;
                pthread_cond_signal(&mycond);
            }
            else
            {
                pthread_cond_wait(&mycond3,&mymutex);
            }

        }
    pthread_mutex_unlock(&mymutex);

    return NULL;
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;

    printf("\nEnter a limit upto which you want to print:");
    scanf("%d",&limit);

    pthread_mutex_init(&mymutex,0);
    pthread_cond_init(&mycond,NULL);
    pthread_cond_init(&mycond2,NULL);
    pthread_cond_init(&mycond3,NULL);

    pthread_create(&thread1,NULL,&myThreadFunc1,NULL);
    pthread_create(&thread2,NULL,&myThreadFunc2,NULL);
    pthread_create(&thread3,NULL,&myThreadFunc3,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    
    printf("\n");
    pthread_mutex_destroy(&mymutex);
    pthread_cond_destroy(&mycond);
    pthread_cond_destroy(&mycond2);
    pthread_cond_destroy(&mycond3);

    return 0;
}

