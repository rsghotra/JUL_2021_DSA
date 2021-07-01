#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;

int buffer = 0;
std::mutex m1;
void task(const char* threadNumber, int loopFor) {
    std::lock_guard<mutex> lock(m1);
    for(int i = 0; i < loopFor; i++) {
        buffer++;
        cout << threadNumber << " " << buffer << endl;
    }
}

int main() {
    thread t1(task, "T1", 10);
    thread t2(task, "T2", 10);

    t1.join();
    t2.join();
    return 0;
}