#ifndef _STACKTP_H_
#define _STACKTP_H_

//typedef unsigned long Item;

template <class Type>
class CStack
{
  private:
    enum {MAX = 10};
    Type items[MAX];
    int top;
  public:
    CStack();
    virtual ~CStack();
  public:
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Type& item);  //push the item to stack
    bool pop(Type& item);  //pop the element to item
};


#endif
