/*

Unique Lock: Expensive lock;

There are different types of mutex acquiring strategy

There are different locking strategies you can utilize 
    - immediately acquiring ownership
    - acquiring ownership after a delay;
    - just acquire lock not ownership
*/
#include<thread>
#include<mutex>
#include<iostream>
#include<chrono>
using namespace std;

std::mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopFor) {
    std::unique_lock<mutex> lock(m1);
    for(int i = 0; i < loopFor; i++) {
        buffer++;
        cout << threadNumber <<  " " << buffer << endl;
    }
    //no need to do unlock as destructor of unique_lock will unlock it;
}

//lock_guard immediately tries to get lock

void task2(const char* threadNumber, int loopFor) {
    std::unique_lock<mutex> lock(m1, std::defer_lock); //Does not call lock on mutex m1, because used defer lock;
    //
    //
    //
    //
    //
    //n - lines of codes;
    lock.lock();
    for(int i = 0; i < loopFor; i++) {
        buffer++;
        cout << threadNumber <<  " " << buffer << endl;
    }
    //lock.unlock in not needed as will be unlocked in destruictor of unique_lock
}


int main() {
    thread t1(task, "T1", 10);
    thread t2(task, "T2", 10);
    t1.join();
    t2.join();
    cout << "======" << endl;
    thread t3(task2, "T3", 10);
    thread t4(task2, "T4", 10);
    t3.join();
    t4.join();
    return 0;
}