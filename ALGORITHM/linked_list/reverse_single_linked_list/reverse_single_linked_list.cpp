#include <iostream>
#include <stdio.h>
#include "../lib/linkedList.h"

using namespace std;

int main(int argc, char **argv)
{
  int a[] = {19,10,8,15,33,31,22,100,87,99};
  CLinkedList *p = new CLinkedList(a, 1);
  p->showLinkedList();

  CSingleNode *p1, *p2, *p3, *first;
  if((p->head == NULL) || (p->head->next ==NULL))
  {
    cout<<"Just one node!"<<endl;
    return 1;
  }  

  p1 = first = p->head;
  p2 = p->head->next;
  while(p2->next != NULL)
  {
    p3 = p2->next;
    p2->next = p1;
    p1 = p2;
    p2 = p3;    
  }
  first->next = NULL;
  cout<<"reverse is:"<<endl;
  p->showLinkedList();


  return 1;
}
