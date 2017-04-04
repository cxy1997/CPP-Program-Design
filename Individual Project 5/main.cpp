#include "seqlist.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    SeqList<char> list(20);
    cout<<"Please input the name of the output file: ";
    char fname[20],t;
    cin>>fname;
    ofstream out(fname);
    cout<<"Please input a sequence of characters (no more than 20):\n";
    cin.ignore(20,'\n');
    out<<"Please input the name of the output file: "<<fname<<endl<<"Please input a sequence of characters (no more than 20):\n";
    int i=0;
    while (1){
        t=cin.get();
        ++i;
        out<<t;
        if (t=='\n') break;
        try
        {
            list.Insert(list.Length(),t);
        }
        catch (StorageExceeded)
        {
            cout<<"Storage Exceeded!\n";
            out<<"Storage Exceeded!\n";
            break;
        }
    }
    t=list.Delete(0);
    list.Insert(list.Length()/2,t);
    cout<<"Display all the elements of the list:\n";
    out<<"Display all the elements of the list:\n";
    for (i=0;i<list.Length();++i)
    {
        cout<<list.Get(i);
        out<<list.Get(i);;
    }
    out.close();
}
