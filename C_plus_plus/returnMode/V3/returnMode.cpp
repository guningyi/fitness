#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;



class CMsg
{
private:
  const char *msgInfo;
  int msgData;
public:
  CMsg(int data,  const char* msg):msgData(data), msgInfo(msg)
  {
      //msgData = data; 
      //msgInfo = msg;
      cout<<"<Constructor>   "<<"msgData=["<<msgData<<"]  "<<"msgInfo=["<<msgInfo<<"]"<<endl;
  }
  virtual ~CMsg()
  {
      cout<<"<Destructor>   "<<"msgData=["<<this->msgData<<"]  "<<"msgInfo=["<<this->msgInfo<<"]"<<endl;
      
  }
  /*copy constructor*/
  CMsg(const CMsg& objMsg)
  {
      int len = strlen(objMsg.msgInfo);
      msgInfo = new char[len+1];
      strcpy(msgInfo, objMsg.msgInfo);
      msgData = objMsg.msgData;
      cout<<"<Copy Constructor>   "<<"msgData=["<<msgData<<"]  "<<"msgInfo=["<<msgInfo<<"]"<<endl;
  }

  void showMsg()
  {
      cout<<"showMsg:"<<msgData<<"+"<<msgInfo<<endl;
      return;
  }
  
  int getMsgData()
  {
      return msgData;
  } 

  std::string getMsgInfo()
  {
      return msgInfo;
  }
 
};

/*
 * Goloble parameter
 * */
CMsg gMsg(10000, "I am goloble parameter!");





/*in parameter: CMsg
 *return : CMsg
 * 
 * */
CMsg opMsg1(CMsg obj)
{
   cout<<"opMsg1 ["<<"parameter:CMsg, return:CMsg ]"<<endl;
   CMsg temp(100, "opMsg1");
   temp = obj;
   return temp;
}

/*
 * in parameter: CMsg& 
 * return :      CMsg
 *
 * */
CMsg opMsg2(CMsg &obj)
{
   cout<<"opMsg2 ["<<"parameter:CMsg, return:CMsg& ]"<<endl;
   CMsg temp(obj);
   return temp;
}


/*
 *  in parameter: CMsg
 *  return: CMsg&
 * */
CMsg& opMsg3(CMsg obj)
{
   cout<<"opMsg3 ["<<"parameter:CMsg, return:CMsg& ]"<<endl;
   gMsg = obj; //operator =
   cout<<"............."<<endl; 
   return gMsg;   
}

/*
 * in parameter: CMsg&
 * return: CMsg&
 *  
 * */
CMsg& opMsg4(CMsg &obj)
{
   cout<<"opMsg4 ["<<"parameter:CMsg&, return:CMsg&]"<<endl;
   CMsg temp(obj);
   return temp;   
}

int main(int argc, char **argv)
{
    const char *pInfo1 = "msg1";
    const char *pInfo2 = "msg2";
    const char *pInfo3 = "msg7";  
   
    CMsg msg999(999, "parameter999");
    CMsg& reMsg = msg999;
    //CMsg& reMsg = CMsg(999, "parameter999"); // initialize reference, this will cause the problem.
    
    CMsg msg1(998, "parameter998");
    //CMsg msg1 = opMsg1(reMsg);// error 
    CMsg msg2 = opMsg1(msg1);// error 
    msg2.showMsg();


    /*if a func parameter is CMsg&
 *
 *  now we pass a value or a reference in it?
 *
 * */

 cout<<"\n-start----------------return value to assigment the variable, pass value---------------"<<endl; 
    CMsg retOpMsg2(0,"I am retOpMsg2");
    retOpMsg2 = opMsg2(msg999); //pass value
    retOpMsg2.showMsg();
 cout<<"-end----------------return value to assigment the variable, pass referance---------------"<<endl; 
    
 cout<<"\n-start----------------return value to assigment the variable, pass referance---------------"<<endl; 
    CMsg retOpMsg3(0,"I am retOpMsg3");
    retOpMsg3 = opMsg2(reMsg); //pass reference
    retOpMsg3.showMsg();
 cout<<"-end----------------return value to assigment the variable,pass referance---------------"<<endl; 

/*
 *when we return a value
 * if we use this value to initialize a reference, then will call copy constructor
 * if we use this value to assigment a reference(not initialize), that's not correct. The compiler will report error
 * if we use this value to assigment a value, then will use the default operator= or that user defined operator=
 * */


/*
 *when we return a reference
 *if we use this reference to initialize a reference. that's not correct, The compiler will report error
 *if we use this reference to initialize a value. will call Copy Constructor
 *if we use this reference to assigment a value(not initialize). will call Constructor
 * */

 cout<<"\n-start----------------initialize obj paraMsg1 and paraMsg2---------------"<<endl; 
 CMsg paraMsg1(0, "I am paraMsg1");
 CMsg paraMsg2(0, "I am paraMsg2");
 cout<<"-end----------------initialize obj paraMsg1 and paraMsg2---------------"<<endl; 

 cout<<"\n-start----------------use reference to initialize the value---------------"<<endl; 
 CMsg reMsg2 = opMsg3(paraMsg1); //use reference to initialize the value.
 reMsg2.showMsg();
 cout<<"-end----------------use reference to initialize the value---------------"<<endl; 


 cout<<"\n-start----------------use reference to assigment the value---------------"<<endl; 
 CMsg reMsg3(0,"I am reMsg3");
 reMsg3 = opMsg3(paraMsg2); //use reference to initialize the value.
 reMsg3.showMsg();
 cout<<"-end----------------use reference to assigment the value---------------"<<endl; 

    return 1;
}
