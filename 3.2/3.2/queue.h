#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;


#define SIZE 10
template <class t> class queue //using template because it allows me to pass anything into it if need be.
{
private:
    t* arr;         // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue
public:
    queue(int size = SIZE);     // constructor

    void pop();//deletes front
    void push(t x);//inserts rear
    t peek();//shows front 
    int size();//tells size 
    bool empty();//checks if empty
    bool full();//checks if full
};

void face();//main because wont work in own file