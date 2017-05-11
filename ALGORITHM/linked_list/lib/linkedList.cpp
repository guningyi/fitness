#include <iostream>
#include <string>
#include <stdio.h>
#include "linkedList.h"

using namespace std;

CLinkedList::CLinkedList(int data[], int type)
{
  cout<<"CLinkedList constructor start!"<<endl;
  //int length = sizeof(data);  得到4，
  //cout<<"array length is:"<<length<<endl;
  head = NULL;
  CSingleNode * temp = NULL; 
  if(type == 1)//single
  {
    temp = head =  new CSingleNode(data[0]);
    for (int i = 1; i < 10; i++)
    {
      CSingleNode *p = new CSingleNode(data[i]);
      temp->next = p;
      temp = p;
    }
    temp->next = NULL;
  }
  return;
}


void CLinkedList::showLinkedList()
{
  CSingleNode *temp = head;
  while(temp != NULL){
    cout<<"linked list is:"<<temp->getData()<<endl;
    temp=temp->next;
  }
  return;
}


