#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;



class CMsg
{
private:
  char *msgInfo;
  int msgData;
public:
  CMsg(int data,  char* msg)
  {
      msgData = data; 
      msgInfo = msg;
      cout<<"Constructor...!"<<endl;
  }
  virtual ~CMsg()
  {
      cout<<"Destructor...!"<<endl;
      delete this->msgInfo;
  }
  CMsg(const CMsg& objMsg)
  {
      int len = strlen(objMsg.msgInfo);
      msgInfo = new char[len+1];
      strcpy(msgInfo, objMsg.msgInfo);
      msgData = objMsg.msgData;
      cout<<"Copy Constructor...!"<<endl;
  }
  
};

int main(int argc, char **argv)
{
    char *pInfo1 = "msg1";
    char *pInfo2 = "msg2";
    CMsg msg1(100,pInfo1);
    CMsg *pMsg2 = new CMsg(200, pInfo2);
    return 1;
}
