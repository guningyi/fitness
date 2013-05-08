#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class A
{
private:
  int a;
  char *c;
public:
  A();
  virtual ~A();
};

A::A()
{
  cout<<"A constructor!"<<endl;
}

A:: ~A()
{
  cout<<"A deconstructor!"<<endl;
}


class B
{

};

class C
{
public:
  C();
  virtual ~C();
  virtual void cc();
  //virtual void ccc() = 0;
private:
  char *pp[5];  
};

C::C()
{
  cout<<"C construcotr!"<<endl;
}

C:: ~C()
{
  cout<<"C deconstructor!"<<endl;
}

void C:: cc()
{
  cout<<"C class cc()!"<<endl;
}

int main(int argc, char **argv)
{
  A *pa;
  A a;
  B *pb;
  B b;
  C c;
  cout<<"sizeof pa is:"<<sizeof(pa)<<endl;
  cout<<"sizeof a is:"<<sizeof(a)<<endl;
  cout<<"sizeof pb is:"<<sizeof(pb)<<endl;
  cout<<"sizeof b is:"<<sizeof(b)<<endl;
  cout<<"sizeof c is:"<<sizeof(c)<<endl;
  return 1;
}
