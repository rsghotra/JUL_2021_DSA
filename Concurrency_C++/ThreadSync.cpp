#include<thread>
#include<mutex>
#include<iostream>
#include<chrono>
using namespace std;

/*
Thread or process syncronization is need to be to done adminter the access to critical section;
Thread or process synchronization is done using LOCKS;
What is critical section: Is a colletion of program statements which must be accessed by only one thread at a time;

*/

long bankBalance = 0;
std::mutex m;
//mutex must be common betwee the two threads;
void addMoney(long val) {
    //this is the critical section;
    //when there is a common variable or object between two threads then it becomes citical section if we are modifying the value;
    //reading value does not posess any issue;
    m.lock();
    bankBalance += val;
    m.unlock();
}

int main() {
    std::thread t1(addMoney, 100);
    std::thread t2(addMoney, 200);
    t1.join();
    t2.join();
    cout << "Final BankBalance: " << bankBalance << endl;
    return 0;
}