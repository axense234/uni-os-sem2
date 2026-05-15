// we have a restaurent and clients want food
// the client is sitting at the table and orders food then
// the client waits until the food is done
// after the order has been fired, the kitchen starts preparing the food
// when the food is done, client starts eating

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond;
pthread_mutex_t mutex;

int isFoodReady = 0; // 0 -> no, 1 -> yes

void *prepareFood(void *arg)
{
    printf("kitchen starts cooking \n");
    sleep(10);

    pthread_mutex_lock(&mutex);
    printf("kitchen is done cooking \n");
    isFoodReady = 1;

    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *eatFood(void *arg)
{

    printf("customer orders food \n");
    pthread_mutex_lock(&mutex);

    while (isFoodReady == 0)
    {
        printf("customer is waiting for food \n");
        pthread_cond_wait(&cond, &mutex);
    }

    printf("customer is eating \n");
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    pthread_t kitchenThread;
    pthread_t customerThread;

    int threadsIds[] = {1, 2};

    pthread_create(&kitchenThread, NULL, prepareFood, &threadsIds[0]);
    pthread_create(&customerThread, NULL, eatFood, &threadsIds[1]);

    pthread_join(kitchenThread, NULL);
    pthread_join(customerThread, NULL);

    return 0;
}
