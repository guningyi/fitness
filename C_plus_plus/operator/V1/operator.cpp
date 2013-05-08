#include <string>
#include <iostream>

using namespace std;

class CMsg;
std::ostream& operator<<(std::ostream& out, const CMsg& msg);

class CMsg{
  friend std::ostream& operator<<(std::ostream& out, const CMsg& msg);
  public:
    CMsg(int data, std::string msg)
    {
        msgData = data;
        msgInfo = msg;
    }
    virtual ~CMsg(){}
    int getData(){return msgData;}
    std::string getInfo(){return msgInfo;}
  private:
    int msgData;
    std::string msgInfo;    
};

std::ostream& operator<<(std::ostream& out, const CMsg& msg)
{
    //out<<msg.getData()<<endl; //error
    //out<<msg.getInfo()<<endl; //error
    out<<msg.msgData<<endl;
    out<<msg.msgInfo<<endl;
    return out;
}

int main(int argc, char **argv)
{
    CMsg msg(10, "We test this operator!");
    cout<<msg;
    return 1;
}
