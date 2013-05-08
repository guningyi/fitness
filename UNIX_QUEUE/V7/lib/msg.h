#ifndef _MSG_H_
#define _MSG_H_

typedef enum 
  {
    TRAFFIC,
    SIGNAL,
  }MsgType;

class CMsg;

CMsg& operator--( CMsg& msg);
const CMsg operator--( CMsg& msg, int);

class CMsg
{
#if 0
  typedef enum 
  {
    TRAFFIC,
    SIGNAL,
  }MsgType;
#endif
  friend CMsg& operator--( CMsg& msg);
  friend const CMsg operator--( CMsg& msg, int);
  //friend std::istream & operator>>(std::istream &in, const CMsg &msg);
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
  public: //overload operator
    void operator+(const CMsg& msg);
    CMsg& operator ++(); //前置操作符
    const CMsg operator ++(int);// 后置操作符
    CMsg& operator=(const CMsg& msg);
    //std::ostream& operator<<(std::ostream &out, const CMsg& msg); //will cause 'must take exactly one argument'
    std::ostream& operator<<(std::ostream& out);
    void showCMsg() const;
  private:
    MsgType msgType;
    int msgData;
    std::string msgInfo; //transfer the shortMsg
  public:
    CMsg *pNext;
    CMsg *pPre;    
};



#endif
