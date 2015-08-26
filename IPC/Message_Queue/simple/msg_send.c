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
	
	if((key = ftok("msg_send.c",'A'))== -1){
		perror("ftok error");
		exit(1);
	}
	
	if((msgid = msgget(key, 0644 | IPC_CREAT)) == -1){
		perror("msgget error");
		exit(1);
	}
	
	printf("Enter lines of text: \n");
	
	buf.mtype = 1;  // if you define many types,you can decide which message will be send
	
	while(fgets(buf.mtext, sizeof(buf.mtext),stdin) != NULL){    //fgets() vs scanf()
		int len = strlen(buf.mtext);
		printf("sizeof = %d length = %d\n",sizeof(buf.mtext),len);
		
		if(buf.mtext[len-1] == '\n'){
			buf.mtext[len-1] == '\0';
		}
		if(msgsnd(msgid, &buf, len+1, 0)){
			perror("msgsnd");	
		}
		
	}
	if(msgctl(msgid,IPC_RMID, NULL) == -1){
		perror("msgctl");
		exit(1);
	}
	return(0);
}	
