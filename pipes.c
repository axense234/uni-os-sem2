#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int pipe1[2], pipe2[2], pipe3[2];

    int pipe1Res = pipe(pipe1);
    int pipe2Res = pipe(pipe2);
    int pipe3Res = pipe(pipe3);

    if (pipe1Res == -1 || pipe2Res == -1 || pipe3Res == -1)
    {
        return -1;
    }

    return 0;
}