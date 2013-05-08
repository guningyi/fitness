#include <iostream>

using namespace std;

class A
{
//private:
 public: 
  int m;
public:
  A(int in);
  virtual ~A();
public:
  virtual void aa();
};

A::A(int in)
{
  this->m = in;
  cout<<"A constructor!"<<endl;
}

A::~A()
{
  cout<<"A deconstructor!"<<endl;
}

void A::aa()
{
  cout<<"m="<<this->m<<endl;
}


int main(int argc, char **argv)
{
  A a(99);
  a.aa();
  char *p1 = reinterpret_cast<char*>(&a);
  char *p2 = reinterpret_cast<char*>(&a.m);
  if (p1 == p2)
  {
    cout<<"vptr is stored in object tail!"<<endl;
  }
  else
  {
    cout<<"vptr is stored in object head"<<endl;
  }
  return 1;
}
