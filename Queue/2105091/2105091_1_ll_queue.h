#include<iostream>
#include "LL.h"
using namespace std;
template<class T>
class Queue
{
    linkedlist<T>list;
    T front;
    T rear;
    int length;
public:
    Queue();

    ~Queue();

    void enqueue(T item);

    T dequeue();

    int Length();

    T Front();

    T back();


    bool is_empty();

    void clear();


    void Print();


    void functionDeclaration();


};



