#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>

#define MAX_MSG_SIZE 256
#define MAX_BUFFER_SIZE (MAX_MSG_SIZE+10)
#define MAX_MESSAGES 10
#define MESS "/m1_test"
#define MESS2 "/m2_test"

struct mq_attr attr;
char buffer[MAX_BUFFER_SIZE];


void send(char buffer[MAX_BUFFER_SIZE]);
void receive();

int main()
{
	char buffer[MAX_BUFFER_SIZE];

	send(buffer);
	printf("Now receiving messages:\n");
	receive();
	send(buffer);
	return 0;

}

void send(char buffer[MAX_BUFFER_SIZE])
{
	memset(buffer,0,MAX_BUFFER_SIZE);

    	int recvr_msgq_fd = 0;

    	printf("\nEnter your message:");
    	fgets(buffer,MAX_BUFFER_SIZE,stdin);

    	if((recvr_msgq_fd = mq_open(MESS, O_WRONLY|O_CREAT,0,0)) == -1)
    	{
        	printf("Client Error, errorno:%d",errno);
        	exit(1);
    	}
	
	if(mq_send(recvr_msgq_fd,buffer,strlen(buffer)+1,0)==-1)
    	{
        	perror("Client not able to send message");
        	exit(1);
    	}
    	mq_close(recvr_msgq_fd);

}

void receive()
{

	fd_set readfds;

	int recvr_msgq_fd=0;
        
	attr.mq_flags = 0;
    	attr.mq_maxmsg = MAX_MESSAGES;
    	attr.mq_msgsize = MAX_MSG_SIZE;
    	attr.mq_curmsgs = 0;

	if((recvr_msgq_fd = mq_open(MESS2, O_RDONLY|O_CREAT,0660,&attr)) == -1)
    	{
        	printf("Client Error, errorno:%d",errno);
        	exit(1);
    	}
	
	printf("Blocked on select()\n");
	
	FD_ZERO(&readfds);
	FD_SET(recvr_msgq_fd,&readfds);
	select(recvr_msgq_fd+2,&readfds,NULL,NULL,NULL);

	if(FD_ISSET(recvr_msgq_fd,&readfds))
	{
		printf("Test1\n");
		memset(buffer,0,MAX_BUFFER_SIZE);
		if(mq_receive(recvr_msgq_fd,buffer,MAX_BUFFER_SIZE,NULL)==-1)
		{
			printf("Error for msgq_receive,errno:%d",errno);
			exit(1);
		}
		printf("Test 2\n");
		printf("Message received:%s\n",buffer);
	}

}

