#include<iostream>
#include "2105091_1_ll_queue.cpp"
//#include "2105091_1_a_queue.cpp"
using namespace std;
template <class T>
class Stack
{
    Queue<T>s;
    int length;
    T top;
public:
    Stack();


   void Clear();

   void push(T item);

   T pop();



   int Length();

   T topValue();

   bool isEmpty();

   void Print();

   void FunctionDeclaration();


};





