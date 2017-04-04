//File name:main.cpp
//This program tests the application of the class Queue.
#include "queue.h"
#include <iostream>
using namespace std;
int main()
{
    cout<<"Please input the queue size: ";
    int Size,i,n;
    cin>>Size; //Prompt the user to input the queue size
    Queue q(Size); //Correspondingly create a queue
    for (i=0;i<Size;++i)
    {
        cout<<"Please input an integer to fill the queue ";
        cin>>n;
        q.enqueue(n);
    } //Ask the user to input a certain number of integer(s) to fill the queue
    q.display(); //Display the queue
    cout<<"This is Dequeue operation: "<<q.dequeue()<<endl; //Delete the first element in the queue
    q.display(); //Display the queue again
}
