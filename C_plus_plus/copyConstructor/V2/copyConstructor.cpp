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
  }
  CMsg(const CMsg& objMsg)
  {
      int len = strlen(objMsg.msgInfo);
      msgInfo = new char[len+1];
      strcpy(msgInfo, objMsg.msgInfo);
      msgData = objMsg.msgData;
      cout<<"Copy Constructor...!"<<endl;
  }
  void showMsg()
  {
      cout<<msgData<<"+"<<msgInfo<<endl;
      return;
  }
  
};


//pass reference
int opMsg1(CMsg& msg)
{
   cout<<"I am opMsg1...!"<<endl;
   return 1; 
}

//pass value
CMsg& opMsg2(int op)
{
   cout<<"op:["<<op<<"]  "<<"I am opMsg2...!"<<endl;
   CMsg temp(op, "opMsg2");
   return temp;
}

//pass value
int opMsg3(CMsg msg)
{
   cout<<"I am opMsg3...!"<<endl;
   return 1; 
}


//return object value
CMsg opMsg4(int op)
{
   cout<<"op:["<<op<<"]  "<<"I am opMsg4...!"<<endl;
   CMsg temp(op, "opMsg4");
   return temp;
}

int main(int argc, char **argv)
{
    char *pInfo1 = "msg1";
    char *pInfo2 = "msg2";
    
    CMsg msg1(100,pInfo1); //call constructor
    CMsg *pMsg2 = new CMsg(200, pInfo2);//call constructor
    CMsg msg3(msg1);  // call copy constructor
 
    cout<<"start ...msg3=msg1..."<<endl;
    msg3 = msg1;  //will not call copy constructor and not call constructor
    msg3.showMsg();
    cout<<"end  ...msg3=msg1..."<<endl;

    CMsg msg4 = msg3; //will call copy constructor

    CMsg *pMsg5 = new CMsg(msg4); //will call copy constructor
 
    msg1.showMsg();
    pMsg2->showMsg();
    msg3.showMsg();
    msg4.showMsg();
    pMsg5->showMsg();

    opMsg1(msg4);  //will not call copy constructor
    opMsg2(2);  // will not call copy constructor
    opMsg3(msg4); //will call copy constructor
    opMsg4(777);  //will not call copy constructor

    CMsg retOpMsg4 = opMsg4(888);

    delete pMsg2; //if didn't use delete this pointer, will not free 'new CMsg(200, pInfo2)'
    delete pMsg5;
    return 1;
}
