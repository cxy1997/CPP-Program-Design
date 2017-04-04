//Note: This program simulates the process of depositing cash by replacing one minute with one second, but waiting is still inevitable.
#include <iostream>
#include "queue.h"  //To utilize classes and fuctions in the Queue library
#include "windows.h"  //To use the function Sleep()
using namespace std;

int SavingsAccount::raised=0;  //The interest rate has not been raised yet

int main()
{
    srand((unsigned)time(NULL));  //To initialize the random number generator
    cout<<"CustID ArriTime FinTime   DepType   DepAmt   IntRates    IntDue    AmtDue\n";
    cout.precision(2);
    cout<<fixed;  //To make the output formatted
    Queue clients;
    int arrival=0,timing=0,count=0;
    SavingsAccount client;
    for (timing=0;(!((count>=20)&&(clients.isEmpty())));++timing)
    {
        if ((arrival==0)&&(count<20))
        {
            ++count;
            if (count==11) client.raise();
            client=SavingsAccount(count,random(1,50)*1000,random(0,5),timing);
            clients.enqueue(client);
            arrival=random(3,8);
        }
        if (!clients.isEmpty()) clients.process(timing);
        if (arrival>0) --arrival;
        Sleep(1000);
    }
}
