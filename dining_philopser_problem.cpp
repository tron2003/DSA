#include <iostream>
#include <vector>
#include <semaphore.h>
#include <unistd.h>
#include <thread>

using namespace std;

const int number_of_philospher = 5;
const int eating_time = 2;

sem_t forks[number_of_philospher];

void helper(int id)
{

    int left = id;
    int right = (id + 1) % 5;
    while (true)
    {

        // sleep(1);

        cout << "philoshper is thinking with id " << id << endl;
        sleep(3);

        cout << "philoshper is hungery and startiing forksss picking wiht id " << id << endl;

        sem_wait(&forks[left]);
        sem_wait(&forks[right]);

        cout << "philoshper start eating" << endl;
        sleep(3);

        sem_post(&forks[left]);
        sem_post(&forks[right]);
        cout << "philoshper finished eating" << endl;
    }
}
int main()
{

    vector<thread> arr;
    for (int i = 0; i < 5; i++)
    {

        sem_init(&forks[i], 0, 1);
    }
    for (int i = 0; i < 5; i++)
    {
        arr.emplace_back(helper, i);
    }
    for (auto &x : arr)
    {

        x.join();
    }
    for (int i = 0; i < 5; i++)
    {

        sem_destroy(&forks[i]);
    }

    return 0;
}