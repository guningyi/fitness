#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  int i = 1;
  vector<int> num(5);
  vector<int>::iterator pNum;
  pNum = num.begin();
  //*pNum = 1;
  
  for(pNum = num.begin(); pNum != num.end(); pNum++)
  {
    *pNum = i++;    
  } 
  i = 1;
  for(pNum = num.begin(); pNum != num.end(); pNum++)
  {
    cout<<"num["<<i++<<"]= "<<*pNum<<endl;
  }
  return 1;
}
