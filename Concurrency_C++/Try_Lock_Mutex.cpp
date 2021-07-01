#include<thread>
#include<iostream>
#include<chrono>
#include<mutex>
using namespace std;

/*
TOPIC: std::mutex::try_lock() On Mutex in C++11 Threading

0. try_lock(): try to lock the mutex. Return immediately; On success lock acquisition returns true else false; 
1. If try_lock() is not able to lock mutex, then it does not get blocked that's why it is called non-blocking;
2. If try+lock() is called again by the same thread which owns the mutex - behavior is undefined;
It is a deadlock sitiation; If you want to be able to lock multiple times using same mutex; then you need to use recursive_mutex

try_lock(): try to lock using mutex;

mtx.lock() - blocking; Thread will wait until the lock is not acquired;

Hence, always use try_lock()
Different types of try_lock()
1. try_lock()
2. mutex::try_lock() --> this video is about this;
3. unique_lock::try_lock()
4. shared_lock::try_lock()
6. timed_mutex::try_lock()
7. shared_mutex::try_lock()
8. recursive_mutex::try_lock()
9. recursive_timed_mutex::try_lock()
10. shared_timed_mutex::try_lock()
*/

int counter = 0;
std::mutex mtx;

void IncreaseTheCounterFor100000Time() {
    for(int i = 0; i < 100000; i++) {
        if(mtx.try_lock()) {
            ++counter;
            mtx.unlock();
        }
        // mtx.lock();
        // ++counter;
        // mtx.unlock();
    }
}

int main() {
    std::thread t1(IncreaseTheCounterFor100000Time);
    std::thread t2(IncreaseTheCounterFor100000Time);
    t1.join();
    t2.join();
    cout << " counter could increase upto: " << counter << endl;
    return 0;
}