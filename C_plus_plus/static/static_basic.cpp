#include <stdio.h>
#include <iostream>

using namespace std;

class Base{
public:
  static void show(){cout << "I am Base!"<<endl;}
  static int a;
  Base(){cout<<"Base constractor!"<<endl;}
  ~Base(){cout << "destractor!"<<endl;}
};

class Derived :public Base{
public:
  Derived(){cout<<"Derived constractor!"<<endl;}
    ~Derived(){
    cout <<"I am Derived"<<endl;
  }

};


int main(int argc, char ** argv)
{
  Base *ptrBase = new Derived();
  ptrBase->show();
  cout<<"ptrBase->a="<<ptrBase->a<<endl;
  return 1;

  

}
