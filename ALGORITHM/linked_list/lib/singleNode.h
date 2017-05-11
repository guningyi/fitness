#ifndef _SINGLE_NODE_H_
#define _SINGLE_NODE_H_
//#include "node.h"
class CSingleNode{
 public:
  CSingleNode(int data);
  void setNodePtr(CSingleNode * next);
  virtual void setData(int data);
  int getData() const;
  CSingleNode * next;
 private:
  int data;
};


#endif
