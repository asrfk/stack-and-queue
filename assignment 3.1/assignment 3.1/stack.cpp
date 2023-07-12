#include "stack.h"
template <class x> stack <x>::stack() { top = -1; } //initializes top to -1 --> default constroctor


template <class x> bool stack <x>::full() {//checks if stack is full
	if (top==(SIZE - 1))
	{
		return 1;//true
	}
	else {
		return 0;//false
	}
}

template <class x> bool stack <x>::empty() {//checks if the stack is empty
	if (top==-1)
	{
		return 1;//true
	}
	else
	{
		return 0;//false
	}
}

template <class x> void stack<x>::push(x elem) {
	if (full()){
		cout << "Stack is Full";
	}
	//cout << "Inserted operator: " << elem << endl;
	vect[++top] = elem;
}

template <class x> x stack<x>::pop() {
	x popped = vect[top];//whatever is at the top is deleted and the top is incremented downwords
	top--;
	return popped;
}

template <class x> x stack<x>::topEl() {
	x top_el = vect[top];
	return top_el;
}

int oper(char c)//assigns values to operators to perform PEMDAS
{
	if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

template <class x>void in_To_post(x s) {

	stack<char> st;
	string result,temp;

	for (size_t i = 0; i < s.size(); i++){
		char c = s[i];

		// checks to see if string is an integer and adds it to the output
		if ((c >= '0' && c <= '9'))
			result += c;

		// if any bracket found pushes on to stack.
		else if (c == '(')
			st.push('(');

		else if (c == '[')
			st.push('[');

		else if (c == '{')
			st.push('{');

		// If closing bracket found its popped until opening bracket is found and added to stack.
		else if (c == ')') {
			while (st.topEl() != '(') {
				result += st.topEl();
				st.pop();
			}
			st.pop();
		}
		else if (c == ']') {
			while (st.topEl() != '[') {
				result += st.topEl();
				st.pop();
			}
			st.pop();
		}
		else if (c == '}') {
			while (st.topEl() != '{') {
				result += st.topEl();
				st.pop();
			}
			st.pop();
		}
		// If an operator is scanned
		else {
			while (!st.empty()
				&& oper(s[i]) <= oper(st.topEl())) {//uses values to perform PEMDAS
				result += st.topEl();
				st.pop();
			}
			st.push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while (!st.empty()) {
		result += st.topEl();
		st.pop();
	}

	cout << result << endl;
}

bool brakbal(string str)
{
	// stack that holds one of the two brakets while iterating. 
	stack<char> temp;
	bool bal=true;
	//throws left hand operators in
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			temp.push(str[i]);
		}
		//checks if left hand element in stack agains right hand element in string
		else if ((temp.topEl() == '(' && str[i] == ')') || (temp.topEl() == '{' && str[i] == '}') || (temp.topEl() == '[' && str[i] == ']')) {
			// if completed pair found remove from stack.
			temp.pop();
		}
	}
	//iterates through stack to see if there are any unbalanced brackets left
	while (!temp.empty())
	{//goes through and sees if there is any operators left
		if (temp.topEl() == '(' || temp.topEl() == '['  || temp.topEl() == '{') {
			bal = false;
		}
		temp.pop();
	}
	return bal;
}

void face()
{//NOTE: keep face in this file. wont work in main().
	stack<string> string_stack;
	string eq,str;

	cout << "ENTER YOUR EQUATION" << endl;
	cin >> eq;//takes user input
	
	if(brakbal(eq)==true){in_To_post(eq);}//begins convertion

	else { cout << " UNBALANCED BRACKETS "; }

}