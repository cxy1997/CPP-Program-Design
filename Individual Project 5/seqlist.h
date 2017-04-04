//File name:seqlist.h
//This program accomplishes the class SeqList and implements its member functions.
#ifndef _SEQUENCELIST_
#define _SEQUENCELIST_
using namespace std;
class NegativeSize{};
class IndexOutOfRange{};
class StorageExceeded{};
template <class ElemType>
class SeqList
{
private:
    ElemType *elem;  // Array to store the data of each element.
    int length;  // Existing element number in the list, also the length of list.
    int MaxSize;  // Maximum size of the array elem.
public:
    SeqList(int InitSize);  // Constructor.
    ~SeqList();  // Destructor.
    void Clear();  // Clear all the elements in the sequence list.
    bool IsEmpty(){return (length==0);}  // Return TRUE if the list is empty, otherwise return FALSE.
    int Length(){return length;}  // Return the length of the list.
    ElemType Get(int i) const;  // Return the value of the ith element.
    int Find(ElemType e) const;  // Return element order if its value is equal to e,
      // return 0 if no such element exists.
    int Insert(int i, ElemType e);  // Insert a new element with the value e in the ith
      // position. Alter the former ith element to the (i+1)th
      // one. Return 1 if inserting is successful, otherwise
      // return 0.
    ElemType Delete(int i);  // Delete the ith element and return its value.
};
template <class ElemType>
SeqList<ElemType>::SeqList(int InitSize)  // Constructor.
{
    if (InitSize<=0) throw NegativeSize();
    MaxSize=InitSize;
    length=0;
    elem=new ElemType[MaxSize];
}
template <class ElemType>
SeqList<ElemType>::~SeqList()  // Destructor.
{
    delete [] elem;
}
template <class ElemType>
void SeqList<ElemType>::Clear()  // Clear all the elements in the sequence list.
{
    length=0;
}
template <class ElemType>
ElemType SeqList<ElemType>::Get(int i) const  // Return the value of the ith element.
{
    if ((i<0)||(i>=length)) throw IndexOutOfRange();
    return elem[i];
}
template <class ElemType>
int SeqList<ElemType>::Find(ElemType e) const  // Return element order if its value is equal to e, return 0 if no such element exists.
{
    for (int i=0;i<length;++i) if (e==elem[i]) return i;
    return 0;
}
template <class ElemType>
int SeqList<ElemType>::Insert(int i, ElemType e)  // Insert a new element with the value e in the ith
      // position. Alter the former ith element to the (i+1)th
      // one. Return 1 if inserting is successful, otherwise
      // return 0.
{
    if ((i<0)||(i>length)) throw IndexOutOfRange();
    if (length==MaxSize) throw StorageExceeded();
    for (int j=length;j>i;--j) elem[j]=elem[j-1];
    elem[i]=e;
    ++length;
}
template <class ElemType>
ElemType SeqList<ElemType>::Delete(int i)  // Delete the ith element and return its value.
{
    if ((i<0)||(i>=length)) throw IndexOutOfRange();
    char t=elem[i];
    for (int j=i;j<length-1;++j) elem[j]=elem[j+1];
    --length;
    return t;
}
#endif
