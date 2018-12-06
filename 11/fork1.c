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
	//switch문 내 n값이 5인 프로세스는 가장 늦게까지 출력되고 3일때 먼저 종료된다.
    switch(pid) 
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        message = "This is the child";
        n = 5;//가장 늦게 종료된 프로세스
        break;
    default:
        message = "This is the parent";
        n = 3;
        break;
    }
    for(; n > 0; n--) {
        puts(message);
        sleep(1);
    }
    exit(0);
}
