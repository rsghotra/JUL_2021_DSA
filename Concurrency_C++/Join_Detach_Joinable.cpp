/*
TOPIC: use of join(), detach(), and joinable() in Thread in C++(C++11)

JOIN NOTES:
0. Once a thread is started we wait for this thread to finish by calling join() function on thread object;
1. Double Join will result into program termination;
2. If needed we should check thread is joinable before joining.

DETACH NOTES
0. used to detach newly created thread from the parent thread.
1. always check before detaching a thread that it is joinable otherwise we may end up double detaching and double detaching terminates the program;
2. if we have detached thread whose process is still ongoing AND main function is approaching it end; then detached thread execution is terminated;

Notes:
Either join() or detach() should be called on thread object, otherise during thread object's destructor
it will will terminate the program. Becuase inside destructor it checks if thread is still joinable? if yes then it terminated the program

*/

#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

void run(int count) {
    while(count-- > 0) {
        cout << count << " CppNuts" << endl;
    }
    // std::this_thread::sleep_for(chrono::seconds(3));
    cout << "thread finished" << endl;
}


int main() {
    std::thread t1(run, 10);
    cout << "main() before" << endl;
    if(t1.joinable()) {
        t1.join();
    }
    if(t1.joinable()) {
        t1.detach();
    }
    cout << "main() after" << endl;
    std::this_thread::sleep_for(chrono::seconds(3));
    return 0;
}