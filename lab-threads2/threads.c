// balance which we want to read and seperately to change it
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int balance = 1000;
pthread_rwlock_t rwlock;

void *reader(void *arg)
{

    int id = *(int *)arg;
    pthread_rwlock_rdlock(&rwlock);
    sleep(7);
    printf("reader %d reads the balance = %d \n", id, balance);

    pthread_rwlock_unlock(&rwlock);
    printf("reader %d finished reading \n", id);

    return NULL;
}

void *writer(void *arg)
{
    int id = *(int *)arg;
    pthread_rwlock_wrlock(&rwlock);
    sleep(12);
    printf("writer %d changes the balances \n", id);
    balance = balance + 999;

    pthread_rwlock_unlock(&rwlock);
    printf("writer %d finished writing with new balance %d \n", id, balance);

    return NULL;
}

int main()
{

    pthread_t readerThreads[3];
    pthread_t writerThread;
    int ids[] = {1, 2, 3, 4};
    pthread_rwlock_init(&rwlock, NULL);

    pthread_create(&readerThreads[0], NULL, reader, &ids[0]);
    pthread_create(&readerThreads[1], NULL, reader, &ids[1]);
    pthread_create(&readerThreads[2], NULL, reader, &ids[2]);
    pthread_create(&writerThread, NULL, writer, &ids[3]);

    pthread_join(readerThreads[0], NULL);
    pthread_join(readerThreads[1], NULL);
    pthread_join(readerThreads[2], NULL);
    pthread_join(writerThread, NULL);

    pthread_rwlock_destroy(&rwlock);

    return 0;
}
