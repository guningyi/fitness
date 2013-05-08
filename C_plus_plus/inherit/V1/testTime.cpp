#include <iostream>
#include <string>
#include <time.h>
//#include <string.h>
using namespace std;


int main(int argc, char **argv)
{
  struct tm now;
  struct tm *pNow = &now;
  //struct tm nowCopy;
  time_t timeTemp;
  time(&timeTemp);
  pNow = localtime(&timeTemp);
  cout<<"Now time is:"<<asctime(pNow)<<endl;
  
  return 1; 


}
