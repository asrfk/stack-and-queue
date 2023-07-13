#include "queue.h"
//default constructor
template <class t> queue<t>::queue(int size) {//sets all variables to 0
	arr = new t[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}
template <class X>bool queue<X>::empty() {return (size() == 0);}      //if size not equal to 0 set false else true 
template <class X>bool queue<X>::full() {return (size() == capacity);}//if size not equal set to false else true

template <class t> void queue<t>::push(t item)
{
    cout << "Inserting " << item << endl;
    rear = (rear + 1) % capacity;//increments the rear allowing for more items to be placed 
    arr[rear] = item;//sets rear to new item
    count++;//increaces count
}

template <class t> void queue<t>::pop() {

    cout << "Removing " << arr[front] << endl<<endl;

    front = (front + 1) % capacity;//decrements the front allowing for a deloading of data
    count--;//reduces count
}
 
template <class t>t queue<t>::peek() { return arr[front]; }//returns the front most item
template <class t>int queue<t>::size() {return count;}//returns count

void face(){//wont work in own cpp for some reason
    {
        
        queue<string> q(4);//creates a variable type queue with size 4
        string input;
        cout << "HELLO!\nPlease enter any item:" << endl;
        while (!q.full()) {//allows me to iterate through until full
            cin >> input;
            q.push(input);//pushes to queue
        }

        cout << "The front element is " << q.peek() << endl;
        cout << "The queue size before deletion is " << q.size() << endl;
        q.pop();//delete front element

        cout << "The queue size after deletion is " << q.size() << endl;

        q.pop();
        q.pop();
        q.pop();

        if (q.empty()) {
            cout << "The queue is now empty\n";
        }
    }
}