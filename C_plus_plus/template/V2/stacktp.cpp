#include <iostream>
#include <string>
#include "stacktp.h"

using namespace std;

template <class Type>
CStack<Type>::CStack()
{
    top = 0;
    cout<<"<Constructor>-CStack:"<<"top= "<<top<<endl;
}

template <class Type>
CStack<Type>::~CStack()
{
    cout<<"<Destructor>-CStack:"<<"top= "<<this->top<<endl;
}

template <class Type>
bool CStack<Type>::isEmpty() const
{
    return top == 0;
} 

template <class Type>
bool CStack<Type>::isFull() const
{
    return top == MAX;
}

template <class Type>
bool CStack<Type>::push(const Type& item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool CStack<Type>::pop(Type& item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}


struct CMsg{
    int msgNo;
    std::string msgInfo;  
};

/*
 *test the template 
 * */
int main(int argc, char **argv)
{
    CStack<CMsg> msgStack;
    int i;
    CMsg msg[10];
    CMsg msgPop;
    for (i = 0; i < 10; i++ )
    {
        msg[i].msgNo = i;
        msg[i].msgInfo = "I am ready!";
        msgStack.push(msg[i]);
    }
    
    while(i-- > 0)
    {
        msgStack.pop(msgPop);
        cout<<"msgStack:"<<"msgNo-"<<msgPop.msgNo<<" "<<"msgInfo '"<<msgPop.msgInfo<<"'"<<endl;
    }
    return 1;
}


