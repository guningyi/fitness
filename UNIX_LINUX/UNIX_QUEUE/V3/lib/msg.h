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
    CMsg(MsgType type,int data, std::string str);
    CMsg();
    //CMsg(const CMsg&);
    virtual ~CMsg();
    MsgType getMsgType();
    int getMsgData();
    std::string getMsgInfo();
    void setMsgData(int data);
    void setMsgType(MsgType type);
    void setMsgInfo(std::string str);
  private:
    MsgType msgType;
    int msgData;
    std::string msgInfo; //transfer the shortMsg
  public:
    CMsg *pNext;
    CMsg *pPre;    
};



#endif
