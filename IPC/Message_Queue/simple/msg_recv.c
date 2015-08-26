#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
//#include<error.h>

struct my_msgbuf{
	long mtype;
	char mtext[200];

};


int main(){
	struct my_msgbuf buf;
	int msgid;
	key_t key;
	
	if((key = ftok("msg_send.c",'A'))== -1){  //same key as msg_send.c
		perror("ftok error");
		exit(1);
	}
	
	if((msgid = msgget(key, 0644 | IPC_CREAT)) == -1){
		perror("msgget error");
		exit(1);
	}
	
	printf("ready to receive message: \n");
	
	buf.mtype = 1;  // if you define many types,you can decide which message will be send
	
	while(1){
		if(msgrcv(msgid ,&buf, sizeof(buf.mtext),1 ,0) == -1){ 
			//the parameter msgtyp  can be 0 or other positive number same as the send message type 
			perror("msgrcv error");
			exit(1);
		}
		printf("%s\n",buf.mtext);	
	}
	
	return(0);
}	
