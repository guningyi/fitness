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
  //  virtual void show(int a){cout<<"I am Derived, a="<<a<<endl;}
  virtual int show(){cout<<"I am Derived"<<endl;
    return 1;}
}; 


int main(int argc, char** argv)
{
  Base *pb = new Derived();  
  pb->show(); 
  delete pb;
  return 1;
}
