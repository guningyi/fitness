#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "singleNode.h"
class CSingleNode;

class CLinkedList{
 public:
  CLinkedList(int data[], int type);
  virtual ~CLinkedList(){};
  CSingleNode * head;
  void showLinkedList();
};
#endif

