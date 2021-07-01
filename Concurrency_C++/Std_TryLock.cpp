#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;
int X = 0, Y = 0;
std::mutex m1, m2;

void SimulateWork(int seconds) {
    std::this_thread::sleep_for(chrono::seconds(seconds));
}


void producer(int& xory, std::mutex& m, string type) {
    for(int i = 0; i < 5; i++) {
        m.lock();
        ++xory;
        cout << type << " " << xory << '\n';
        m.unlock();
        SimulateWork(1);
    }
}

void consumer() {
    int consumerCount = 5;
    int xplusy = 0;
    while(1) {
        int lockResult = std::try_lock(m1, m2); // need to lock both as we need to access 
        if(lockResult == -1) {
            if(X > 0 && Y > 0) {
                --consumerCount;
                xplusy += X + Y;
                X = 0;
                Y = 0;
                cout << "XplusY " << xplusy << '\n';
            }
        }
        m1.unlock();
        m2.unlock();
        if(consumerCount == 0) break;
    }
}

int main() {
    std::thread t1(producer, std::ref(X), std::ref(m1), "X");
    std::thread t2(producer, std::ref(Y), std::ref(m2), "Y");
    std::thread t3(consumer);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}