#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "./lib/exception.h"

using namespace std;

int throw_exception_zero(int len)
{
    return 10/len; 
}


void throw_exception_print(std::string ss)
{
    cout<<"ss is:"<<ss<<endl;
    return;
}

int main(int argc, char **argv)
{
   //test the exception class
   
   std::string msg;
   try{
       throw_exception_zero(1);
       throw_exception_print("hello world!");
   }
   catch(CException &e)
   {
       cout<<e.what()<<endl;
       return 1;
   }
   catch(CException &e)
   {
       cout<<e.what()<<endl;
       return 1;
   }
   cout<<"No any Exception!"<<endl;
   return 0;
}
