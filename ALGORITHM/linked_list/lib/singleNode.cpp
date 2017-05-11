#include "singleNode.h"
#include <iostream>
#include <stdio.h>

using namespace std;

CSingleNode::CSingleNode(int data){
  this->data = data;
  this->next = NULL;
}

void CSingleNode::setNodePtr(CSingleNode* next)
{
  this->next = next;
  return ;
}

void CSingleNode::setData(int data)
{
  this->data = data;
  return;
}

int CSingleNode::getData() const
{
  return this->data;
}
