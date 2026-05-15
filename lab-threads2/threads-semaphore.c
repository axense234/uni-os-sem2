// voters are going to vote and are all allocated to a voting section
// a voting section has 2 voting cabins
// if there is a free cabin then a voter enters and votes
// if all cabins are busy then the voter waits until one is free

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t semaphore;

void *vote(void *arg)
{
    int id = *(int *)arg;
    sleep(rand() % 3);
    printf("voter %d has arrived to the voting section \n", id);

    sem_wait(&semaphore);
    printf("voter %d enters the cabin \n", id);

    sleep(rand() % 5);

    printf("voter %d has voted \n", id);

    sem_post(&semaphore);

    return NULL;
}

int main()
{
    int NB_VOTERS = 233;
    int NB_CABINS = 2;

    pthread_t voterThreads[NB_VOTERS];
    int voterThreadsIds[NB_VOTERS];

    sem_init(&semaphore, 0, NB_CABINS);

    for (int i = 0; i < NB_VOTERS; ++i)
    {
        voterThreadsIds[i] = i;
        pthread_create(&voterThreads[i], NULL, vote, &voterThreadsIds[i]);
    }

    for (int i = 0; i < NB_VOTERS; ++i)
    {
        pthread_join(voterThreads[i], NULL);
    }

    sem_destroy(&semaphore);

    return 0;
}
