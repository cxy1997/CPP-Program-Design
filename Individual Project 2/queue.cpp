//file name:queue.cpp
//This file realizes the queue library.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int inf,int sup)
{
    return inf+(rand()*(sup-inf+1)/(RAND_MAX+1));
}  //To generate a random number between inf and sup (both included)

inline SavingsAccount::SavingsAccount(int ID,int AMOUNT,int TYPE,int ATIME)
{
    id=ID;
    amount=AMOUNT;
    type=TYPE;
    arriveTime=ATIME;
    lasting=random(2,7);
    rate=Rates[raised][type];
    interestDue=amount*0.008*rate*Types[type];
    amountDue=amount+interestDue;
}  //Initialize the client's session

bool SavingsAccount::process()
{
    lasting-=1;
    return (lasting==0);
}  //To simulate the work of the stuff

void Queue::process(int currentTime)
{
    if (data[0].process())
    {
        data[0].finishat(currentTime);
        ++served;
        cout<<dequeue();
    }
}  //To simulate the work of the stuff

void Queue::enqueue(const SavingsAccount& sa)
{
    if (size<20)
    {
        data[size]=sa;
        ++size;
    }
}  //Add a client into the queue

SavingsAccount Queue::dequeue()
{
    SavingsAccount temp;
    if (size>0)
    {
        temp=data[0];
        int i;
        for (i=0;i<size-1;++i) data[i]=data[i+1];
        --size;
    }
    return temp;
}  //To remove the first client in the queue and return it

ostream& operator<<(ostream& os,const SavingsAccount& sa)
{
    os<<setw(4)<<sa.id<<setw(8)<<sa.arriveTime<<setw(9)<<sa.finishTime<<setw(10)<<Types[sa.type]<<setw(12)<<sa.amount<<setw(8)<<sa.rate<<setw(12)<<sa.interestDue<<setw(10)<<sa.amountDue<<endl;
    return os;
}  //Out put a line that has been formatted
