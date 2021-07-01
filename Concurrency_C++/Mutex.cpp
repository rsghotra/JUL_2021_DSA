/*
Mutex: Mutual Exclusion

//RACE CONDITION:
0. Race is a situation where two or more processes or threads happend to change a common data at the same time.
1. if there is a race condition then we have to protect it and the protected section is called critical region;

MUTEX:
0. Mutex is used to avoid race condition
1. We used lock() and unlock() on mutex to avoid race condition

Simultaneously modifying the data;
Simultaneously accessing is not issue;
*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int myAmount = 0;
std::mutex m;

//critical section here;
//if t1 and t2 happen to load x at the same time then myAmount == 1
void AddMoney() {
    m.lock();
    ++myAmount; //--> c.s.
    m.unlock();
}


int main() {
    std::thread t1(AddMoney);
    std::thread t2(AddMoney);

    t1.join();
    t2.join();

    cout << myAmount << endl;
    return 0;
}
