#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<iostream>
using namespace std;

template<class T>
class Triangle {
private:
    T side1;
    T side2;
    T side3;
    T base;
    T height;
public:
    Triangle(T side1, T side2, T side3);
    T getArea();
    void setSide1(T side);
    void setSide2(T side);
    void setSide3(T side);
    void setBase(T base);
    void setHeight(T height);
    T getHeight();
};

#endif