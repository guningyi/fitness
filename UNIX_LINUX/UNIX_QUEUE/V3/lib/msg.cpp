#include <iostream>
#include <vector>
#include <string>
#include "msg.h"

using namespace std;

CMsg::CMsg()
{
   msgType = MsgType(0);
   msgData = 0;
   pNext = NULL;
   pPre = NULL;
   cout<<"CMsg constructor!"<<endl;
}

CMsg::CMsg(MsgType type, int data, string str)
{
   msgType = type;
   msgData = data;
   msgInfo = str; 
   pNext = NULL;
   pPre = NULL;
   cout<<"CMsg constructor..."<<endl;
}
#if 0
CMsg::CMsg(const CMsg& obj)
{
    cout<<"start Copy_Constructor.."<<endl;
    pNext = obj.pNext;
    pPre = obj.pPre;
    CMsg temp = obj;   //un-finish cycle.
    msgType = temp.getMsgType();
    msgData = temp.getMsgData();
    msgInfo = temp.getMsgInfo();
    cout<<" msgInfo length is : "<<msgInfo.length()<<endl;
    cout<<"finish Copy_Constructor.."<<endl;
    
}
#endif

CMsg::~CMsg()
{
   //delete pNext;  //segfault error. wrong use the delete.
   //delete pPre;   //segfault error. wrong use the delete.
   cout<<"Destructor the CMsg!"<<endl;
   pNext = NULL;
   pPre = NULL;
}

MsgType CMsg::getMsgType()
{
    return msgType;
}   

int CMsg::getMsgData()
{
    return msgData;
}

void CMsg::setMsgData(int data)
{
    msgData = data;
    return;
}    

void CMsg::setMsgType(MsgType type)
{
    msgType = type;
    return;
}

void CMsg::setMsgInfo(string str)
{
     msgInfo = str;; 
     return;
}

string  CMsg::getMsgInfo()
{
    return msgInfo;
}
