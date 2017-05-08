#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "msg.h"

class CMsg;

class CQueue
{
  friend class CMsg;
  public:
    CQueue(int len);
    virtual ~CQueue();
    bool initQueue(int len);
    virtual bool InQueue(CMsg *in);
    virtual bool OutQueue();
    const CMsg& getQueueMsg();
    bool IsQueueEmpty()const; //const member function, this means function will not change the class member, just look.
    int getCurrLength();
    int getMaxLength();    
    void setCurrLength(int len);
    void setMaxLength(int len);
  public:
    CMsg *pfront;
    CMsg *pend;
  private:
    int Currentlength;
    int Maxlength;
};


#endif 
