// we want to send an email to customers
// when all emails are sent print out an its done message

#include <pthread.h>
#include <stdio.h>

pthread_barrier_t barrier;

void *sendEmail(void *arg)
{
    int id = *(int *)arg;

    printf("sending email for %d \n", id);

    pthread_barrier_wait(&barrier);
    printf("promotion done \n");

    return NULL;
}

int main()
{
    int NB_CUSTOMERS = 12;

    pthread_t clients[NB_CUSTOMERS];
    int threadsIds[NB_CUSTOMERS];

    pthread_barrier_init(&barrier, NULL, NB_CUSTOMERS);

    for (int i = 0; i < NB_CUSTOMERS; ++i)
    {

        threadsIds[i] = i;
        pthread_create(&clients[i], NULL, sendEmail, &threadsIds[i]);
    }

    for (int i = 0; i < NB_CUSTOMERS; ++i)
    {

        pthread_join(clients[i], NULL);
    }

    pthread_barrier_destroy(&barrier);

    return 0;
}
