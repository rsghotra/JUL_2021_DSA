/*
std::timed_mutex

try_lock immediately returns if it is not able to acquire lock;
std::timed_mutex m;
m.try_lock_for: will not return immediately but try to acquire lock for x seconds;
m.try_lock_until: some event happens;

Member functions:
a. lock
b. try_lock
c. try_lock_for         ___\
d. try_lock_until       ___/ these tow functions differentiacte std::mutex and std::timed_mutex
e. unlock
*/

#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;

int myAmount = 0;
std::timed_mutex m;

void increment_try_lock_for(int i) {
    if(m.try_lock_for(std::chrono::seconds(2))) {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Thread " << i << " Entered" << endl;
        m.unlock();
    } else {
        cout << "Thread " << i << " Could not Enter" << endl;
    }
}

void increment_try_lock_until(int i) {
    auto now = std::chrono::steady_clock::now();
    if(m.try_lock_until(now + std::chrono::seconds(2))) {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Thread " << i << " Entered" << endl;
        m.unlock();
    } else {
        cout << "Thread " << i << " Could not enter" << endl;
    }
}

int main() {
    std::thread t1(increment_try_lock_until, 1);
    std::thread t2(increment_try_lock_until, 2);
    t1.join();
    t2.join();

    cout << myAmount << endl;
    return 0;
}