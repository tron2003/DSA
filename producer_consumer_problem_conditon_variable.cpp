#include <iostream>
#include <chrono>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <queue>

using namespace std;
const int max_buffer = 5;
queue<int> que;
int curr_buffer = 0;
mutex mtx;
condition_variable buffer_full;
condition_variable buffer_empty;

void producer(int id)
{

    int value = 0;
    while (true)
    {

        unique_lock<mutex> lock(mtx);
        buffer_full.wait(lock, []
                         { return curr_buffer < max_buffer; });
        que.push(value);
        cout << "Prodcuer " << "id :" << id << "value " << value << endl;

        value++;
        curr_buffer++;

        buffer_empty.notify_one();
        lock.unlock();
        this_thread::sleep_for(chrono::seconds(1));
    }
}
void consumer(int id)
{
    while (true)
    {

        unique_lock<mutex> lock(mtx);
        buffer_empty.wait(lock, []
                          { return curr_buffer >0; });
        int value = que.front();
        que.pop();

        cout << "consumer " << "id :" << id << "value " << value << endl;

        curr_buffer--;

        buffer_full.notify_one();
        lock.unlock();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

using namespace std;

int main()
{
    thread consumers[2], producers[2];
    for (int i = 0; i < 2; i++)
    {

        producers[i] = thread(producer, i);
        consumers[i] = thread(consumer, i);
    }
    for (int i = 0; i < 2; i++)
    {

        producers[i].join();
        consumers[i].join();
    }

    return 0;
}