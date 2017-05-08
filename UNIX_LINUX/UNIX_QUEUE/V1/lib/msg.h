#ifndef _MSG_H_
#define _MSG_H_

typedef enum 
  {
    TRAFFIC,
    SIGNAL,
  }MsgType;

class CMsg
{
#if 0
  typedef enum 
  {
    TRAFFIC,
    SIGNAL,
  }MsgType;
#endif
  public:
    CMsg(MsgType type,int data);
    CMsg();
    virtual ~CMsg();
    MsgType getMsgType();
    int getMsgData();
  private:
    MsgType msgType;
    int msgData;
  public:
    CMsg *pNext;
    CMsg *pPre;    
};



#endif
