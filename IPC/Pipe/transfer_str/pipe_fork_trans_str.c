#include<stdio.h>
#include<stdlib.h>	// To use exit(),nust include
#include<unistd.h>	// To use pipe()
#include<sys/types.h>	// To use pid_t
#include<string.h>

int main(){

	int fd[2], nbytes;
	pid_t child_pid;
	char *string = "Hello,world!\n";
	char readbuffer[20];

	pipe(fd);
	
	if((child_pid = fork()) == -1){
		perror("fork error");
		exit(1);
	}

	if(child_pid == 0){
		close(fd[0]);
		write(fd[1],string,(strlen(string)+1));
		exit(0);
	}else{
		printf("parent first \n");
		close(fd[1]);
		nbytes = read(fd[0],readbuffer, sizeof(readbuffer));
		printf("Received string: %s",readbuffer);
	}
	exit(0);
}
