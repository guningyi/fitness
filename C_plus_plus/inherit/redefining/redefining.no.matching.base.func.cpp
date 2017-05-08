#include <iostream>

using namespace std;

class Base{
public:
  Base(){cout<<"constructor Base!"<<endl;}
  virtual ~Base(){cout<<"destructor Base!"<<endl;}
  virtual void show(){cout<<"I am Base!"<<endl;}
};


class Derived:public Base{
public:
  Derived(){cout<<"constructor Derived!"<<endl;}
  virtual ~Derived(){cout<<"destructor Derived!"<<endl;}
  virtual void show(int a){cout<<"I am Derived, a="<<a<<endl;}
}; 


int main(int argc, char** argv)
{
  Base *pb = new Derived();  
  pb->show(100); //编译出错 ， no matching function for call to ‘Base::show(int),为什么这里pb没有调用其实际指向的类的方法？
  delete pb;
  return 1;
}
