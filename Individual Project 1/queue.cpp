//file name:queue.cpp
//This file realizes the queue library.
#include <iostream>
#include <cstdlib>
using namespace std;
Queue::Queue(int num)
{
    if ((num>=0)&&(num<=10))
    {
        size=0;
        max=(10>num)?num:10;
    } else
    {
        cout<<"Error: incorrect queue size.\n";
        exit(1);
    }
} //Initialize the queue
Queue::Queue(const Queue &q)
{
    size=q.size;
    max=q.max;
    int data[10];
    for (int i=0;i<max;++i) data[i]=q.data[10];
}//Copy constructor
bool Queue::enqueue(int num) //Add a number to the tail of the queue, returning false if failing to add
{
    if (size<max)
    {
        ++size;
        data[size-1]=num;
        return true;
    } else
    {
        cout<<"Error: The queue is full.\n";
        return false;
    }
}
int Queue::dequeue() //Remove a number from the head of  the queue and return it
{
    if (size>0)
    {
        int temp=data[0],i;
        for (i=0;i<size-1;++i) data[i]=data[i+1];
        --size;
        return temp;
    } else
    {
        cout<<"Error: There are no elements left to dequeue.\n";
        return 0;
    }
}
int Queue::peek(int num) const //Return the element in the position i of the queue, without removing the element
{
    if ((num>0)&&(num<max+1)) return data[num-1];
    else cout<<"Error: Queue index out of range.\n";
}
int Queue::getSize() const //Return the current size of the queue
{
    return size;
}
void Queue::display() const //Output and display all the elements in the current queue on the screen
{
    cout<<"There ";
    if (size>1) cout<<"are "; else cout<<"is ";
    cout<<size<<" element";
    if (size>1) cout<<'s';
    cout<<" in the queue.";
    if (size>1)
    {
        cout<<" They are:\n";
        int i;
        for (i=0;i<size;++i) cout<<data[i]<<' ';
        cout<<endl;
    } else if (size==1) cout<<" It is:\n"<<data[0]<<endl; else cout<<endl;
}
