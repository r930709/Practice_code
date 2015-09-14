#include<stdio.h>
#include<stdlib.h>
struct commands{
	int (*fptr)();
	int key;
};
typedef struct commands Cmd;
int do_a(void), do_b(void),do_c(void);

int main(){
	int ch, key;

	Cmd commandlist[]=
	{
		do_a, 'a',
		do_b, 'b',
		do_c, 'c',
		NULL, '\0'
	};
	Cmd *cmd_ptr;
	
	while(1){
		ch = getchar();
		if(ch =='q'){	break;	}
		
		cmd_ptr = commandlist;
		for(;key = cmd_ptr->key;cmd_ptr++){
			if(ch == key){
				cmd_ptr->fptr();
				break;
			
			}
			printf("%p \n",cmd_ptr);	
		}
	}

	return(0);
}

int do_a(){
	printf("push a\n");
	return(0);
}
int do_b(){
	printf("push b\n");
	return(0);
}
int do_c(){
	printf("push c\n");
	return(0);
}
