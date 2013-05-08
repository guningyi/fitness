#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include <iostream>


const int num = 32;

class CMsg;
class CQueue;


std::ostream& operator<<(std::ostream& out, const CMsg& msg);

class CMsg{
  friend class CQueue;
  friend std::ostream& operator<<(std::ostream& out, const CMsg& msg);
  public:
    CMsg(int data, std::string msg);
    virtual ~CMsg();
    int getData();
    std::string getInfo();
  private:
    int msgData;
    std::string msgInfo;    
    CMsg *next;
};


class CQueue
{
  friend class CMsg;
  //overload operator new
  static void* operator new(unsigned int size);
  //overload operator delete
  static void operator delete(void* p);
  public:
    CQueue();
    virtual ~CQueue();
  private:
    static CMsg* p_free;
    //CMsg *next;
};

#endif
