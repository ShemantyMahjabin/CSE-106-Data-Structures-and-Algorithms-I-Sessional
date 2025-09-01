#include<iostream>
#include "Arr.h"

using namespace std;
template <class T>
class Queue
{
    arraylist<T>arr;
public:


    void enqueue(int x);

    T dequeue();

    int Length();

    T Front();

    T back();

    bool is_empty();

    void clear();


    void Print();


    void functionDeclaration();


};




