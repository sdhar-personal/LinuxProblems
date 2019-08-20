#include<stdio.h>
#include<pthread.h>
struct parms
{
	int a;
	int b;
};

void *addnumbers(void *parameters)
{
	struct parms *p = (struct parms *)parameters;
	int i;

	i = p->a+p->b;
	
	printf("%d+%d=%d\n",p->a,p->b,i);
	
	return NULL;
}

void *subnumbers(void *parameters)
{
        struct parms *p = (struct parms *)parameters;
        int i;

        i = p->a-p->b;

        printf("%d-%d=%d\n",p->a,p->b,i);

        return NULL;
}

void *mulnumbers(void *parameters)
{
        struct parms *p = (struct parms *)parameters;
        int i;

        i = p->a*p->b;

        printf("%d*%d=%d\n",p->a,p->b,i);

        return NULL;
}

void *divnumbers(void *parameters)
{
        struct parms *p = (struct parms *)parameters;
        float i;

        i =((float)(p->a))/((float)(p->b));

        printf("%d/%d=%0.2f\n",p->a,p->b,i);

        return NULL;
}

int main()
{

	pthread_t thread1_id;
	pthread_t thread2_id;
	pthread_t thread3_id;
	pthread_t thread4_id;

	struct parms thread_args;

	while(1)
	{
		printf("\nEnter a number: ");
		scanf("%d",&thread_args.a);
		printf("\nEnter another number: ");
		scanf("%d",&thread_args.b);

		pthread_create(&thread1_id,NULL,&addnumbers,&thread_args);
		pthread_create(&thread2_id,NULL,&subnumbers,&thread_args);
		pthread_create(&thread3_id,NULL,&mulnumbers,&thread_args);
		pthread_create(&thread4_id,NULL,&divnumbers,&thread_args);

		pthread_join(thread1_id,NULL);
		pthread_join(thread2_id,NULL);
		pthread_join(thread3_id,NULL);
		pthread_join(thread4_id,NULL);
	}

	return 0;
}


