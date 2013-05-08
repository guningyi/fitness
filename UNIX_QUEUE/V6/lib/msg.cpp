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
   cout<<"CMsg destructor!"<<endl;
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


//overload the +
void CMsg::operator+ (const CMsg& msg) 
{
    //CMsg msg;
    msgInfo += msg.msgInfo;
    msgData += msg.msgData;
    return ;
}

CMsg& CMsg::operator ++()
{
   msgData++;
   return *this; 
}


const CMsg CMsg::operator ++(int)
{
    CMsg temp = *this;
    ++(this->msgData);
    return temp;
}

//全局 函数 但不是成员函数
CMsg & operator--( CMsg& msg)
{
    msg.msgData--;
    return msg;
}

const CMsg operator--(CMsg& msg, int)
{
    CMsg temp = msg;
    --(msg.msgData);
    return temp;
}



void CMsg::showCMsg() const
{
    cout<<"Type is : "<<msgType<<endl;
    cout<<"Data is : "<<msgData<<endl;
    cout<<"Info is : "<<msgInfo<<endl;
    cout<<"---------------------------------"<<endl;
    return;
}


CMsg& CMsg::operator=(const CMsg& msg)
{
    //protect self assigment
    if (this == &msg) 
    {
        return *this;
    }
    msgType = msg.msgType;  
    msgData = msg.msgData;
    msgInfo = msg.msgInfo;
    return *this; 
}


std::ostream& CMsg::operator<<(std::ostream& out)
{
   out<<"msgType is : ["<<this->msgType<<"]"<<endl;
   out<<"msgData is : ["<<this->msgData<<"]"<<endl;
   out<<"msgInfo is : ["<<this->msgInfo<<"]"<<endl;
   return out;
}

#if 0
std::isteram& operator>>(std::istream& in, CMsg &msg)
{
    
   in>>"msgType is : ["<<msg.msgType<<"]"<<endl;
   in>>"msgData is : ["<<msg.msgData<<"]"<<endl;
   in>>"msgInfo is : ["<<msg.msgInfo<<"]"<<endl;
   return in;
}
#endif
