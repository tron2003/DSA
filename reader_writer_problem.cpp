#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>
#include <vector>

using namespace std;

sem_t wrt;          // Semaphore for writer access
sem_t mut;          // Semaphore for reader count access
int read_count = 0; // Number of readers

void reader(int id)
{
    while (true)
    {
        sleep(5); // Simulate random reading intervals

        // Entry section for readers
        sem_wait(&mut);
        read_count++;
        if (read_count == 1)
        {
            sem_wait(&wrt); // First reader locks the resource for writers
        }
        sem_post(&mut);

        // Reading section
        cout << "Reader " << id << " is reading." << endl;
        sleep(5); // Simulate reading duration

        // Exit section for readers
        sem_wait(&mut);
        read_count--;
        if (read_count == 0)
        {
            sem_post(&wrt); // Last reader unlocks the resource for writers
        }
        sem_post(&mut);

        sleep(5); // Simulate time between reads
    }
}

void writer(int id)
{
    while (true)
    {
        sleep(5); // Simulate random writing intervals

        sem_wait(&wrt); // Writer locks the resource

        // Writing section
        cout << "Writer " << id << " is writing." << endl;
        sleep(5); // Simulate writing duration

        sem_post(&wrt); // Writer unlocks the resource

        sleep(5); // Simulate time between writes
    }
}

int main()
{
    srand(time(NULL)); // Seed for random number generation

    // Initialize semaphores
    sem_init(&wrt, 0, 1);
    sem_init(&mut, 0, 1);

    vector<thread> readers;
    vector<thread> writers;

    for (int i = 0; i < 5; ++i)
    {
        readers.emplace_back(reader, i + 1);
    }

    for (int i = 0; i < 2; ++i)
    {
        writers.emplace_back(writer, i + 1);
    }

    for (auto &th : readers)
    {
        th.join();
    }

    for (auto &th : writers)
    {
        th.join();
    }

    // Destroy semaphores
    sem_destroy(&wrt);
    sem_destroy(&mut);

    return 0;
}
