#include <iostream>
#include <vector>
#include <map>
#include "queue.h"
using namespace std;

class CMsg;

CQueue::CQueue(int len)
{
    
    cout<<"CQueue constructor start!"<<endl; 
    pfront = pend = NULL;
    Maxlength = len;
    Currentlength = 0;
    cout<<"CQueue constructor ok!"<<endl;
    cout<<"Queue MAX Length is : ["<<Maxlength<<"]"<<endl;
}

CQueue::~CQueue()
{
    Currentlength = 0;
    pfront = pend = NULL;
    cout<<"CQueue destructor!"<<endl; 
}

bool CQueue::initQueue(int len)
{
    
}



//insert to CQueue tail
bool CQueue::InQueue(CMsg *in)
{
   if ( Currentlength >= Maxlength ) 
   {
      cout<<"Queue full!"<<endl;
      return false;
   }
   cout<<"InQueue start1!"<<endl;
   CMsg *msgPtr = new CMsg(in->getMsgType(), in->getMsgData());

   cout<<"InQueue start2!"<<endl;
   if (pend == NULL) //first node
   {
       cout<<"pend is NULL"<<endl;
       pfront = pend = msgPtr;
       pfront->pNext = pend->pPre = pend->pNext = pfront->pPre = NULL;
       Currentlength++;
       return true;
   }
   else if (pend != NULL)
   {
       cout<<"pend is not NULL"<<endl;
       
       msgPtr->pPre = pend;
       pend->pNext = msgPtr;
       pend = msgPtr;
       msgPtr = NULL;
       Currentlength++;
       return true;
   }
   cout<<"InQueue start3!"<<endl;
}


// return quote
// don't return the locality paramter quote.
// but the CMsg that has been exist before the OutQueue be called.
bool CQueue::OutQueue()
{
   if ((Currentlength == 0) && (pfront != NULL))
   {
       cout<<"queue is empty!"<<endl;
       return false;
   }

   //only one CMsg node.
   if(pfront->pNext == NULL)
   {
       cout<<"Only one node!"<<endl;
       delete pfront;
       pfront = pend = NULL;
       return true;
       Currentlength = 0;
   }
   else//not the last one
   {
       cout<<"Not the Last node!"<<endl;
       CMsg *temp = pfront;
       pfront = pfront->pNext;
       pfront->pPre = NULL;
       temp->pNext = NULL;
       //delete temp; //segfault error
       temp = NULL;
       Currentlength-- ;
       return true;
   } 
   return false;
}

bool CQueue::IsQueueEmpty()const
{
    if ( Currentlength == 0 )
    {
        cout<<"Queue is empty!"<<endl;
        return true;
    }
    else
        return false;
}


void CQueue::travelQueue() const
{
    int i = Currentlength - 1;
    cout<<"Travel the Queue form front to tail...!"<<endl;
    if ( Currentlength == 0 )
    {
        cout<<"Queue is empty!"<<endl;
        return;
    }
    CMsg *temp = pfront;
    while( temp != NULL )
    {
        cout<<"Node["<<(Currentlength - i)<<"]:"<<endl;
        cout<<"Type is : "<<temp->getMsgType()<<endl;
        cout<<"Data is : "<<temp->getMsgData()<<endl;
        cout<<"---------------------------------"<<endl;
        temp = temp->pNext;
        i--; 
    }
    return;
}



int CQueue::getCurrLength()
{
    return Currentlength;
}

int CQueue::getMaxLength()
{
    return Maxlength;
}

void CQueue::setCurrLength(int len)
{
    
}


void CQueue::setMaxLength(int len)
{

}

const CMsg& CQueue::getQueueMsg()
{
   if ( pfront != NULL ) 
   {
       return *pfront;
   }
}

