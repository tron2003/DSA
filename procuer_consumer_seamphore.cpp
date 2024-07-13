#include <iostream>
#include <thread>
#include <vector>
#include <semaphore.h>
#include <unistd.h>

using namespace std;
const int BUFFER_SIZE = 10; // Size of the buffer
int buffer[BUFFER_SIZE];    // Buffer to store data
int in = 0;                 // Index to insert data
int out = 0;                // Index to remove data

sem_t emp;  // Semaphore to count emp slots in the buffer
sem_t full; // Semaphore to count full slots in the buffer
sem_t mut;  // Semaphore to ensure mutual exclusion

void producer(int id)
{
    int item;
    while (true)
    {
        item = rand() % 100;
        sleep(1);
        sem_wait(&emp);
        sem_wait(&mut);

        buffer[in] = item;
        cout << "Producer" << " id " << id << " value" << item << endl;
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&full);
        sem_post(&mut);
        sleep(1);
    }
}

void consumer(int id)
{
    int item;
    while (true)
    {
        sleep(1);
        sem_wait(&full);
        sem_wait(&mut);

        item = buffer[out];
        cout << "Conumser" << " id " << id << " value" << item << endl;
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&emp);
        sem_post(&mut);
        sleep(1);
    }
}

int main()
{
    // Seed for random number generation

    sem_init(&emp, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mut, 0, 1);
    vector<thread> producers;
    vector<thread> consumers;
    for (int i = 0; i < 3; i++)
    {
        producers.emplace_back(producer, i + 1);
    }
    for (int i = 0; i < 3; i++)
    {
        consumers.emplace_back(consumer, i + 1);
    }
    for (auto &producer_thread : producers)
    {
        producer_thread.join();
    }

    // Join consumer threads
    for (auto &consumer_thread : consumers)
    {
        consumer_thread.join();
    }
    sem_destroy(&emp);
    sem_destroy(&full);
    sem_destroy(&mut);
    return 0;
}
