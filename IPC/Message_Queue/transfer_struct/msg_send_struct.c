#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
//#include<error.h>

typedef struct stacknode NODE;
struct my_msgbuf{
	long mtype;
	struct private_info{
		char name[30];
		char number[20];
		char email[30];
		int height;
		float weight;		

	}info;

};


int main(){
	struct my_msgbuf buf;
	int msgid;
	key_t key;
	
	
//-------------msg_queue_start---------------------------------------------------------------------------------------//
	if((key = ftok("msg_send_struct.c",'A'))== -1){  //same key as msg_send.c
		perror("ftok error");
		exit(1);
	}
	
	if((msgid = msgget(key, 0644 | IPC_CREAT)) == -1){
		perror("msgget error");
		exit(1);
	}
	printf("input your name:");
	scanf("%s",buf.info.name);
	printf("input your phone number:");
	scanf("%s",buf.info.number);
	printf("input your email:");
	scanf("%s",buf.info.email);
	printf("input your height:");
	scanf("%d",&buf.info.height);
	printf("input your weight:");
	scanf("%f",&buf.info.weight);
	buf.mtype = 1;  // if you define many types,you can decide which message will be send
	
	printf("[ready to transfer info...] \n");

		if(msgsnd(msgid ,&buf, sizeof(buf)-sizeof(buf.mtype),0) == -1){ 
			//the parameter msgtyp  can be 0 or other positive number same as the send message type 
			perror("msgsnd error");
			exit(1);
		}
		printf("sizeof(buf): %d sizeof(buf.info) %d\n",sizeof(buf),sizeof(buf.info));
		printf("[stack send complete...]\n");
	
//--------------------------------------------------------------------------------------------------------------------//	
	if(msgctl(msgid, IPC_RMID,NULL)==-1){
		perror("msgctl error");
		exit(1);
	}
	return(0);
}	
