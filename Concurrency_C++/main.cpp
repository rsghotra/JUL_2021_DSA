/*

std::promise and std::future
Very useful when you need any local variable from a running thread in the main process;

1. std::promise
    - setter
    - used to set values and exceptions
2. std::future
    - getter
    - user to get values from promise;
    - ask promise if the value is available;
    - blocking
    - wait for the promis


*/

#include<iostream>
#include<thread>
#include<future>
#include<algorithm>
#include<chrono>
using namespace std;
using namespace std::chrono;

void findOdd(std::promise<int>&& oddSumPromise, int start, int end) {
    int oddSum = 0;
    for(int i = start; i <= end; i++) {
        if((i & 1)) {
            oddSum += i;
        }
    }
    oddSumPromise.set_value(oddSum);
}

int main() {
    int start = 0; int end = 1900000;
    //make a promise object;
    std::promise<int> oddSumPromise;
    std::future<int> oddSumFuture = oddSumPromise.get_future();
    cout << "Thread created!" << endl;
    std::thread t1(findOdd, std::move(oddSumPromise), start, end);

    cout << "Waiting for result!!" << endl;
    cout << "OddSum: " << oddSumFuture.get() << endl;
    cout << "Completed!" << endl;
    t1.join();
    return 0;
}