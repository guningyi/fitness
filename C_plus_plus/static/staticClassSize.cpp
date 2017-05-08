#include <iostream>

using namespace std;

class Base{
  static void show(){cout<<"I am Base!"<<endl;}
  static int a;
  int b;
};

int main(int argc, char** argv){
  cout<<"size of Base is:"<<sizeof(Base)<<endl;
  return 1;
}
