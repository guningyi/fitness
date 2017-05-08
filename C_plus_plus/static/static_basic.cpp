#include <stdio.h>
#include <iostream>

using namespace std;

class Base{
public:
  static show(){cout << "I am Base!"<<endl;}
  static int a = 20;
  ~Base(){cout << "destractor!"<<endl;}
}

class Derived :public Base{
public:
  ~Derived(){
    cout <<"I am Derived"<<endl;
  }

}


int main(int argc, char ** argv)
{
  Base *ptrBase = new Derived();
  ptrBase->show();
  return 1;
  

}
