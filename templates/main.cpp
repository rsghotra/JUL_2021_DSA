#include<iostream>
#include "Triangle.h"
using namespace std;


int main() {
	Triangle<int> tngl(10,20,30);
	tngl.setHeight(15);
	tngl.setBase(20);
	cout << "Height is: " << tngl.getHeight() << endl;
	cout << "The area is: " <<  tngl.getArea() << endl;
	return 0;
}