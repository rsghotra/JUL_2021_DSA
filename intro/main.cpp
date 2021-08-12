#include<iostream>
using namespace std;


void Head(int x) {
    if(x > 0) {
        cout << x << endl;
        Head(x-1);
    }
}

void Tail(int x) {
    if(x > 0) {
        cout << x << endl;
        Tail(x-1);
    }
}

int static_global(int n) {
    static int x  = 0;
    if(n > 0) {
        x++;
        return static_global(n-1) + x;
    }
    return 0;
}

int main() {
    int x  = 3;
    cout << "Head: " << endl;
    Head(x);
    cout << "Tail: " << endl;
    Tail(x);

    cout << "Static + Global" << endl;
    cout << static_global(5) << endl;

    cout << "Static + Global" << endl;
    cout << static_global(5) << endl;


    return 0;
}