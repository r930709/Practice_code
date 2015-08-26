#include<stdio.h>
#include<stdlib.h> 
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	
	int fifo_server,fifo_client;
	char str[256];
 	char *buf;
 	int choice=1;
 	
	mknod("fifo_server",S_IFIFO | 0666,0);          
	mkfifo("fifo_client",0666);	
	
	printf("Choose the request to be sent to server from options below");
 	printf("\n\t\t Enter 1 for O.S.Name \n \
                Enter 2 for Distribution \n \
                Enter 3 for Kernel version \n");
 	scanf("%d",&choice);

        fifo_server=open("fifo_server",O_RDWR);
 	if(fifo_server < 0) {
  		printf("Error in opening file");
  		exit(-1);
  	}

 	write(fifo_server,&choice,sizeof(int));

	fifo_client=open("fifo_client",O_RDWR);
  	if(fifo_client < 0) {
  		printf("Error in opening file");
  		exit(-1);
  	}

 	buf=malloc(80*sizeof(char));
 	
	read (fifo_client,buf,80*sizeof(char));
 	printf("\n ***Reply from server is %s***\n",buf);
 	
	close(fifo_server);
	close(fifo_client);
	
	return(0);
}
