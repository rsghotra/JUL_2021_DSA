//https://www.youtube.com/watch?v=TPVH_coGAQs&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=1
#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void FindEven(ull start, ull end) {
    for(ull i = start; i <= end; i++) {
        if((i&1) == 0) {
            EvenSum += i;
        }
    }
}

void FindOdd(ull start, ull end) {
    for(ull i = start; i <= end; i++) {
        if((i&1) == 1) {
            OddSum += i;
        }
    }
}

int main() {
    ull start = 0, end = 1900000000;
    cout << "Introduction to Thread!" << endl;
    auto startTime = high_resolution_clock::now();
    std::thread t1(FindOdd, start, end);
    std::thread t2(FindEven, start, end);
    t1.join();
    t2.join();

    // FindOdd(start, end);
    // FindEven(start, end);

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "OddSum: " << OddSum << endl;
    cout << "EvenSum: " << EvenSum << endl;
    cout << "Time it took: " << duration.count() / 1000000 << " seconds." << endl;
    return 0;
}

