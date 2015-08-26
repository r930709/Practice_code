/*
	Sample progam illustrating the use of Unix pipes between processes.
	Paul Krzyzanowski

	This forks and execs two commands (cmd1 and cmd2), with the standard output of 
	cmd1 going to the standard input of cmd2.
	
	The commands are:
	cmd1:
		/bin/ls -al /
		lists all the files in the root directory in the long format
	cmd2:
		/usr/bin/tr a-z A-Z
		translates all input from lowercase to uppercase
	Feel free to modify cmd1 and cmd2 to get them to work on your system or to do something differnt.

	Key points:

	Processes start with three open file descriptors. File descriptor 0 is
	the standard input and is typically the keyboard input. File descriptor 1
	is the standard output and is typically the virtual terminal that is the
	window where the shell is running. File descriptor 2 is the standard error
	and is typically the same as the standard output. If the standard output
	is redirected to a file or another command, errors can still be sent to 
	the screen where a user can see them.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char *cmd1[] = {"/bin/ls", "-al", "/", NULL};
char *cmd2[] = {"/usr/bin/tr", "a-z" , "A-Z" , NULL}; 

void Runpipe();
void Runpipe(int pfd[],int pid){
	
	switch(pid){

	case 0: // child
		dup2(pfd[0], 0);
		close(pfd[1]);
		execvp(cmd2[0],cmd2);
		perror(cmd2[0]);
	default: //parent
		dup2(pfd[1],1);
		close(pfd[0]);
		execvp(cmd1[0],cmd1);
		perror(cmd1[0]);
	case -1:
		perror("fork error");
		exit(1);	
	}
}

int main(){
	int pid,status;
	int fd[2];

	pipe(fd);
	
	switch(pid = fork()){
	
		case 0:	// child
			Runpipe(fd,pid);
			exit(0);
		default: // parent
			Runpipe(fd,pid);
			exit(0);				
		case -1:
			perror("fork error");
			exit(1);
	}
	
	exit(0);
}


