#include<thread>
#include<mutex>
#include<iostream>
#include<chrono>
using namespace std;



/*
std::lock() in C++ 11; ==> v.v.v. important topic
BLOCKING CALL; TRY ALL WAY TO GET LOCK ON ALL mutexes; NO DEADLOCK
ALGO IS NOT KNOWN
YOU HAVE TO UNLOCK THEM IF USING SIMPLE MUTEXES

it is not m1.lock() but it is std::lock
IT TRY TO ACQUIRE LOCK IN NON_DEADLOCK MANNER;
Capability: std::lock() is used to lock multiple mutex at the same time;

IMP:
1. Syntax: std::lock(m1, m2, m3, m4);

All arguments are locked via a sequence of calls to lock(), try_lock(), or unlock() on each argument;
Order of locking is not defined(it will try to lock provided mutex and ensure that there is no deadlock)
It is a BLOCKING call;

[Example:0] ==> no deadlock
Thread 1               Thread 2
std::lock(m1, m2);     std::lock(m1, m2)


[Example:1] ==> no deadlock
Thread 1               Thread 2
std::lock(m1, m2);     std::lock(m2, m1)

[Example:2] ==> no deadlock
Thread 1               Thread 2
std::lock(m1, m2, m3, m4);     std::lock(m3, m4); std::lock(m1, m2)

[Example:3] ==> DEADLOCK
Thread 1               Thread 2
std::lock(m1, m2, m3, m4);     std::lock(m3, m4); std::lock(m1, m2)


*/

std::mutex m1, m2;

void task_a() {
    while(1) {
        std::lock(m1, m2);
        cout << "task a" << endl;
        m1.unlock();
        m2.unlock();
    }
}

void task_b() {
    while(1) {
        std::lock(m2, m1);
        cout << "task b" << endl;
        m2.unlock();
        m1.unlock();
    }
}


int main() {
    thread t1(task_a);
    thread t2(task_b);

    t1.join();
    t2.join();
    return 0;
}