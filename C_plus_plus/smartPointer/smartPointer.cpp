#include <iostream>
#include <string>

using namespace std;

class CMsg
{
  private:
    int msgData;
    std::string msgInfo;
  public:
    CMsg(int data, std::string msg) : msgData(data), msgInfo(msg){}
    virtual ~CMsg(){}
    void showCMsg(){cout<<msgData<<"+"<<msgInfo<<endl;}
};


class SP
{
  private:
    CMsg *pMsg;
    int count;
  public:
    SP(CMsg *p)
    {
        pMsg = p;
        count = 0;    
    }
    virtual ~SP(){}
    CMsg* operator->()
    { 
        count++;  
        return pMsg;
    } 
    int number_of_access_cmsg()
    {
        return count;
    }
};



int main(int argc, char **argv)
{
    CMsg msg(100, "Hello world!");
    SP smartPointer(&msg);
    smartPointer->showCMsg();
    smartPointer->showCMsg();
    cout<<smartPointer.number_of_access_cmsg()<<endl;
    
    return 1;
}
