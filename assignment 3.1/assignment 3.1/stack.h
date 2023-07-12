#pragma once
#include <iostream>
#include <string>
#include <bits.h>
#include <vector>
#include <sstream>
#include <ctype.h>
using namespace std;
//assigns size to stack. 
#define SIZE 30


//template allows for ease of use when implementing variables.
template< class x> class stack
{
public:
	stack();//defaul constructor
	void push(x elem);//adds element
	x pop();//remove top element
	x topEl();//prints top element
	bool empty();//checks if empty
	bool full();//checks if full
private:
	int top;//is top item
	x vect[SIZE];//container

};

template<class x>
void in_To_post(x s);//convert infix to postfix
void face();//main function
int oper(char c);//checks if all charachters are valid. 
bool brakbal(string expr);
