#include <iostream>
#include <vector>
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

CMsg::CMsg(MsgType type, int data)
{
   msgType = type;
   msgData = data;
   pNext = NULL;
   pPre = NULL;
   cout<<"CMsg constructor!"<<"..."<<"msgType="<<type<<"||"<<"msgData="<<data<<endl;
}

CMsg::~CMsg()
{
   delete pNext;
   delete pPre;
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


