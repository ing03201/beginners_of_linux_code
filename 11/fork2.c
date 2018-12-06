#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;

    printf("fork program starting\n");
    pid = fork();
    switch(pid) 
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        message = "This is the child";
        n = 3;
        break;
    default:
        message = "This is the parent";
        n = 5;
        break;
    }

	/*
	   해당 코드는 자식프로세스가 먼저 모두 출력되고 부모프로세스가 두번 더 출력된다.
	   부모 프로세스와 자식프로세스가 동시에 일어나는것을 보여준다.
	*/
    for(; n > 0; n--) {
        puts(message);
        sleep(1);
    }
    exit(0);
}
