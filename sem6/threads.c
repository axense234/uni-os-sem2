#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// sum 100 000 numbers
// mutex
pthread_mutex_t mutex;
pthread_rwlock_t rwlock;

int count = 0;
// volatile count = 0;

void *f(void *a)
{
    int index = *(int *)a;
    for (int i = 0; i < 100000; i++)
    {
        // lock
        pthread_mutex_lock(&mutex);
        count = count + 1;
        pthread_mutex_unlock(&mutex);
    }

    printf("thread %d func used\n", index);
    return NULL;
}

int main()
{
    // write a program that creates 10 threads and prints the thread index

    // 10 threads
    // pthread_t allocate memory with malloc

    // create 10 threads
    // pthread_create(thread variable, NULL, function_to_exec, func_args)

    pthread_t *threads = malloc(10 * sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);
    pthread_rwlock_init(&rwlock, NULL);
    for (int i = 0; i < 10; i++)
    {
        pthread_create(&threads[i], NULL, f, &i);
    }

    // join -> similar to wait for processes
    // pthread_join(thread variable, NULL)
    for (int i = 0; i < 10; i++)
    {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_rwlock_destroy(&rwlock);

    printf("expected: 1 000 000 \n");
    printf("count variable is equal to %d \n", count);

    return 0;
}
