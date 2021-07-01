#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int buffer = 0;
std::recursive_mutex m1;
std::recursive_mutex m2;


//recursive example of recursive_mutex
void recursion(string thr, int loopFor) {
    if(loopFor < 0) {
        return;
    }

    m1.lock();
    cout << "Thread# " + thr << " " << buffer++ << endl;
    recursion(thr, --loopFor);
    m1.unlock();
}

//iterative example
void iterative_example() {
    for(int i = 0; i < 5; i++) {
        m2.lock();
        cout << "locked " << i << endl;
    }

    for(int i = 0; i < 5; i++) {
        m2.unlock();
        cout << "unlocked " << i << endl;
    }
}

int main() {
    thread t1(recursion, "1", 10);
    thread t2(recursion, "2", 10);
    t1.join();
    t2.join();

    iterative_example();
    return 0;
}

//iterative example of recursive_mutex

