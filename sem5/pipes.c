#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

int main()
{

    int pipeEx[2];
    int pipeRes = pipe(pipeEx);

    if (pipeRes == -1)
    {
        // printf("something went wrong, errno: %d \n", errno);
        perror("pipe failed");
    }

    if (fork() == 0)
    {
        // int k = 8;
        // write(pipeEx[1], &k, sizeof(k));

        // exit(0);

        dup2(pipeEx[1], 1);

        execlp("ls", "ls", NULL);
        exit(0);
    }
    else
    {
        // int kRes;
        // int readRes = read(pipeEx[0], &kRes, sizeof(kRes));

        // printf("kRes: %d, readRes: %d\n", kRes, readRes);
        // wait(0);

        char buf[4096] = {0};
        read(pipeEx[0], buf, sizeof(buf));
        printf("buf: %s\n", buf);
    }

    close(pipeEx[0]);
    close(pipeEx[1]);

    return 0;
}