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

struct my_msgbuf show_info(struct my_msgbuf my_info){
	printf("name : %s\n",my_info.info.name);
	printf("phone number : %s\n",my_info.info.number);
	printf("email : %s\n",my_info.info.email);
	printf("height : %d\n",my_info.info.height);
	printf("weight : %f\n",my_info.info.weight);

}


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
	
	printf("[ready to recv info...] \n");

	//while(1){
		if(msgrcv(msgid ,&buf, sizeof(buf)-sizeof(buf.mtype),1,0) == -1){ 
			//the parameter msgtyp  can be 0 or other positive number same as the send message type 
			perror("msgrcv error");
			exit(1);
		}
		printf("[personal info recv complete...]\n");
		show_info(buf);
	//}
//--------------------------------------------------------------------------------------------------------------------//	
	return(0);
}	
