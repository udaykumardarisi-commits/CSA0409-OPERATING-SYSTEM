#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int count = 0;
int in = 0, out = 0;

pthread_mutex_t mutex;

void* thread1(void* arg) {
    int id = *(int*)arg;
    for(int i = 1; i <= 7; i++) {
        pthread_mutex_lock(&mutex);
        if(count < BUFFER_SIZE){
            buffer[in] = i;
            in = (in + 1) % BUFFER_SIZE;
            count++;
            printf("Thread %d added: %d. Buffer count: %d\n", id, i, count);
        } else {
            printf("Thread %d: Buffer FULL. Cannot add %d\n", id, i);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* thread2(void* arg) {
    int id = *(int*)arg;
    for(int i = 1; i <= 7; i++) {
        pthread_mutex_lock(&mutex);
        if(count > 0){
            int item = buffer[out];
            out = (out + 1) % BUFFER_SIZE;
            count--;
            printf("Thread %d removed: %d. Buffer count: %d\n", id, item, count);
        } else {
            printf("Thread %d: Buffer EMPTY. Cannot remove\n", id);
        }
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, thread1, &id1);
    pthread_create(&t2, NULL, thread2, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    printf("All operations finished. Final buffer count: %d\n", count);
    return 0;
}
