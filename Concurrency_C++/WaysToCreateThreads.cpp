#include<iostream>
#include<thread>
using namespace std;


//1. Funtion Pointers
void fun(int x) {
    while(x > 0) {
        cout << x << " ";
        x--;
    }
    cout << endl;
}

int FunctionPointer() {
    std::thread t(fun, 10);
    t.join();
    return 0;
}

//2, Lambda Function

int LambdaFunction() {
    std::thread t1([](int x) {
        while( x > 0 ) {
            cout << x << " ";
            x--;
        }
        cout << endl;
    }, 10);
    t1.join();
    return 0;
}

//3, Functors
class Base  {
    public:
        void operator()(int x) {
            while(x > 0) {
                cout << x << " ";
                x--;
            }
            cout << endl;
        }
};

int Functors() {
    std::thread t1((Base()), 11);
    t1.join();
    return 0;
}

//4. Non Static Member Functions
class Base2 {
    public:
        void fun(int x) {
            while(x > 0) {
                cout << x << " ";
                x--;
            }
            cout << endl;
        }
};

int NonStaticMemberFun() {
    Base2 b2;
    //careful not fun()
    std::thread t1(&Base2::fun,&b2, 10);
    t1.join();
    return 0;
}

//5. Static Member Function
class Base3 {
    public:
        static void fun(int x) {
            while(x > 0) {
                cout << x << " ";
                x--;
            }
            cout << endl;
        }
};

int main() {
    std::thread t1(&Base3::fun, 13);
    t1.join();
    return 0;
}
