#include <iostream>
using namespace std;
 
class Array{
 
private:
    int* A;
    int size;
    int length;
 
public:
    Array(int size){
        this->size = size;
        A = new int [size];
    }
 
    void create(){
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++){
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }
 
    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }
 
 
    void reverse(Array* arr) {
        for(int i = 0, j = arr->length - 1; i < j; i++, j--) {
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp; 
        }
    }
    ~Array(){
        delete[] A;
        cout << "Array destroyed" << endl;
    }

    bool is_sorted(Array* arr) {
        for(int i = 0; i < arr->length-1; i++) {
            if(arr->A[i] > arr->A[i+1]) {
                return false;
            }
        }
        return true;
    }
    
    void swap(int& num1, int& num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    void SegregatePositiveAndNegative(Array* arr) {
        int i = 0;
        int j = arr->length-1;
        while(i < j) {
            while(arr->A[i] < 0) {
                i++;
            }
            while(arr->A[j] >= 0) {
                j--;
            }
            if(i < j) {
                swap(arr->A[i], arr->A[j]);
            }
        }
    }

};

int main() {
 
    Array arr(10);
    arr.create();
    arr.display();
    //arr.reverse(&arr);
    arr.SegregatePositiveAndNegative(&arr);
    arr.display();
    return 0;
}