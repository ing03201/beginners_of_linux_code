#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define N 10
void main(void){
	pid_t pid[N];
	int i, child_status;

	for(i = 0; i < N; i++)
		if((pid[i] = fork()) == 0){
			exit(100+i);
		}
	for(i = 0; i< N; i++){
		pid_t wpid = wait(&child_status);
		if(WIFEXITED(child_status)) //child 프로세스가 종료되었을때 
			printf("Child %d terminated with exit status %d\n",wpid, WEXITSTATUS(child_status));
		else //child 프로세스가 종료되지않았을때
			printf("Child %d terminate abnormally\n",wpid);
	}
}
