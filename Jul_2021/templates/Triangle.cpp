#include<iostream>
#include "Triangle.h"
using namespace std;

template<class T>
Triangle<T>::Triangle(T side1, T side2, T side3) {
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}

template<class T>
T Triangle<T>::getArea() {
    return  (this->base * this->height)/2.0;
}

template<class T>
void Triangle<T>::setSide1(T side) {
    this->side1 = side;
}

template<class T>
void Triangle<T>::setSide2(T side) {
    this->side2 = side;
}

template<class T>
void Triangle<T>::setSide3(T side) {
    this->side3 = side;
}

template<class T>
void Triangle<T>::setBase(T base) {
    this->base = base;
}

template<class T>
void Triangle<T>::setHeight(T height) {
    this->height = height;
}

template<class T>
T Triangle<T>::getHeight() {
    return this->height;
}

//https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class Triangle<int>;
template class Triangle<float>;