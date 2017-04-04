//File name:queue.h
//Header file of queue library
#ifndef QUEUE
#define QUEUE
class Queue
{
private:
    int size,max; //Record the current size of the queue and its limit
    int data[10]; //Memorize data integers
public:
    Queue(int); //Initialize the queue
    Queue(const Queue&);//Copy constructor
    bool enqueue(int); //Add a number to the tail of the queue, returning false if failing to add
    int dequeue(); //Remove a number from the head of  the queue and return it
    int peek(int) const; //Return the element in the position i of the queue, without removing the element
    int getSize() const; //Return the current size of the queue
    void display() const; //Output and display all the elements in the current queue on the screen
};
#include "queue.cpp"
#endif
