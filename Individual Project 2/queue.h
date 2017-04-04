//File name:queue.h
//Header file of queue library
#ifndef QUEUE
#define QUEUE
#include <iostream>
using namespace std;

const double Rates[2][6]={{1.71,2.07,2.25,2.70,3.24,3.60},{1.80,2.25,2.52,3.06,3.69,4.14}};  //Different rates
const double Types[6]={0.25,0.5,1,2,3,5};  //Different maturities

class SavingsAccount
{
private:
    int id,type,arriveTime,lasting,finishTime;
    double amount,rate,interestDue,amountDue;
    static int raised;
public:
    SavingsAccount(int ID,int AMOUNT,int TYPE,int ATIME);
    SavingsAccount():id(0),amount(0),type(1),arriveTime(0){}
    friend ostream& operator<<(ostream& os,const SavingsAccount& sa);
    void raise(){raised=1;}
    bool process();
    void finishat(int FTime){finishTime=FTime;}
};  //To simulate a single client

class Queue
{
private:
    SavingsAccount data[20];
    int size,served;
public:
    Queue(){size=0;served=0;}
    void enqueue(const SavingsAccount& sa);
    SavingsAccount dequeue();
    bool noMoreClients(){return (served>=20);}
    bool isEmpty(){return (size==0);}
    void process(int currentTime);
};  //To simulate a queue of clients

int random(int inf,int sup);  //To generate a random number between inf and sup (both included)
#include "queue.cpp"
#endif
