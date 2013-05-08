#include <string>
#include <string.h>
#include <iostream>
#include "operator.h"

using namespace std;

class CMsg;

CMsg::CMsg(int data, std::string msg)
{
    msgData = data;
    msgInfo = msg;
}

CMsg::~CMsg()
{

}
    
int CMsg::getData()
{
    return msgData;
}
    
std::string CMsg::getInfo()
{
    return msgInfo;
}

std::ostream& operator<<(std::ostream& out, const CMsg& msg)
{
    //out<<msg.getData()<<endl; //error
    //out<<msg.getInfo()<<endl; //error
    out<<msg.msgData<<endl;
    out<<msg.msgInfo<<endl;
    return out;
}

  //overload operator new
void* CQueue::operator new(unsigned int size)
{
    cout<<"Entry the operator new!"<<endl;
    CMsg *pMsg;
    if ( NULL == p_free ) 
    {
        p_free = (CMsg*) new char[size * num];
        for(pMsg = p_free; pMsg != (p_free + num - 1); pMsg++)
        {
           //pMsg = pMsg->next;
           pMsg->next = pMsg + 1;
        }
        pMsg->next = NULL;
    }   
    pMsg = p_free;
    p_free = p_free->next;

    memset(p_free, 0, size);
    return pMsg;
}

//overload operator delete
void CQueue::operator delete(void* p)
{
  cout<<"Entry the operator delete!"<<endl;
  ((CMsg*)p)->next = p_free;
  p_free = (CMsg*)p;      

}

CQueue::CQueue()
{

}

CQueue::~CQueue()
{

}
    
CMsg* CQueue::p_free = NULL;
    


