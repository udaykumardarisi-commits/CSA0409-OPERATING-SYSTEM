#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  

sem_t forks[N];   
pthread_t tid[N]; 

void *philosopher(void *num) {
    int id = *(int *)num;

    while(1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        sem_wait(&forks[id]);
        sem_wait(&forks[(id+1) % N]);

        printf("Philosopher %d is eating.\n", id);
        sleep(2);

        sem_post(&forks[(id+1) % N]);
        sem_post(&forks[id]);

        printf("Philosopher %d finished eating and is thinking again.\n", id);
        sleep(1);
    }
}

int main() {
    int i, id[N];

    for(i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    for(i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &id[i]);
    }

    for(i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}
