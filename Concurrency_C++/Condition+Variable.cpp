/*

Condition Variable: It is a notification mechanism to let the thread or threads in waiting know that they can resume their work;

CV is used for two purpose:

1. Notify other threads
2. Waiting for some conditions;

Concept:

Apply:

In order for a thread to wait on a CV it has to do:

1. Acquire the mutex lock using std::unique_lock<mutex> lock(m);
2. Exeute wait, wait_for, or wait_until, the wait OPERATIO AUTOMATICALLY RELEASE THE MUTEX & SUSPEND execution of thread
3. WHEN CV is notified - thread awake and mutex is automatically re-acquired
4. THREAD cheks the CV to see if it was a false alarm


Condition variable could also be used if you would like to certain which thread to start

NOTE:
CV are used to synchronize two or more threads;
Best use case of condition variable is Producer/Consumer problem;


*/


#include<thread>
#include<mutex>
#include<iostream>
#include<chrono>
#include<condition_variable>
using namespace std;

std::mutex m;
std::condition_variable cv;
long balance = 0;

void depositMoney(int amount) {
    std::lock_guard<mutex> lg(m);
    balance+= amount;
    cout << "Balance after adding amount : " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int amount) {
    //1. acquire mutex;
    std::unique_lock<mutex> ul(m);
    //2. Execute wait; when cv lamda returns true then it will execute further; else will wait
    cv.wait(ul, [] {return (balance != 0) ? true: false;});
    //3. thread awakens re-acquire mutex;
    //4. check if it was not a false alarm
    if(balance >= amount) {
        balance -= amount;
        cout << "Amount deducted: " << amount << endl;
    } else {
        cout << "Amount can't be deducted, Current Balance is lower " << amount << endl;
    }
    cout << "Current Balance is: " << balance << endl;
} 

int main() {
    thread t1(withdrawMoney, 600);
    //look carefully no . operator
    //std::this_thread::sleep_for(std::chrono::seconds(10));
    thread t2(depositMoney, 500);
    t1.join();
    t2.join();
    return 0;
}

