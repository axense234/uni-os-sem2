#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    pid_t children[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        pid_t theChild = fork();
        if (theChild == 0)
        {
            sleep(i);
            printf("Child %ld finished\n", getpid());
            exit(0);
        }
        else
        {
            children[i] = theChild;
        }
    }

    for (int i = 4; i >= 0; i--)
    {
        pid_t theDeadChild = waitpid(children[i], NULL, 0);
        printf("Parent found child %ld dead\n", theDeadChild);
    }
}