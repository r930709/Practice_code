#include<stdio.h> 
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int fifo_server,fifo_client;
	int choice;
	char *buf;
	
	mknod("fifo_server", S_IFIFO | 0666,0);
	mkfifo("fifo_client", 0666);	

	fifo_server = open("fifo_server",O_RDWR);
	if(fifo_server<1) {
 		printf("Error opening file");
 	}
		read(fifo_server,&choice,sizeof(int));
	
	fifo_client = open("fifo_client",O_RDWR);
	if(fifo_server<1) {
 		printf("Error opening file");
 	}

	switch(choice) {

		case 1: 
 			buf="Linuxiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
 			write(fifo_client,buf,80*sizeof(char)); 
 			printf("\n Data sent to client \n");
 			break;
		case 2:

 			buf="debianfjdkfjkdjfkdjfkjdkfjkdjfkdjsfk";
 			write(fifo_client,buf,80*sizeof(char)); 
 			printf("\nData sent to client\n");
 			break;
		case 3: 
 			buf="2.6.32vvvvvvvvvvvvvvvvvvvvvvvvv!!!!!!!!1";
 			write(fifo_client,buf,80*sizeof(char)); 
 			printf("\nData sent to client\n");
		}

		close(fifo_server);
		close(fifo_client);
}
