#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

atomic<bool> flag[2];
atomic<int> turn;

void peterson(int id, int otherId)
{
    for (int i = 0; i < 5; ++i)
    {
        // Entry section
        flag[id] = true;
        turn = otherId;
        while (flag[otherId] && turn == otherId)
        {
            // Busy wait
        }

        // Critical section
        cout << "Thread " << id << " is in critical section." << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Thread " << id << " is leaving critical section." << endl;

        // Exit section
        flag[id] = false;

        // Remainder section
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main()
{
    flag[0] = false;
    flag[1] = false;
    turn = 0;

    thread t1(peterson, 0, 1);
    thread t2(peterson, 1, 0);

    t1.join();
    t2.join();

    return 0;
}
