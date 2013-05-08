#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  int i = 1;
  int j = 1;
  vector<char> word1(5);
  vector<char> word2(5);
  vector<char>::iterator pword1;
  vector<char>::iterator pword2;

  pword1 = word1.begin();
  pword2 = word2.begin();

  for (;pword1 != word1.end(), pword2 != word2.end(); pword1++, pword2++)
  {
    *pword1 = 'a';
    *pword2 = 'b';
  }


  pword1 = word1.begin();
  pword2 = word2.begin();

  for (;pword1 != word1.end(), pword2 != word2.end(); pword1++, pword2++)
  {
    cout<<"word1["<<i++<<"]="<<*pword1<<endl;
    cout<<"word2["<<j++<<"]="<<*pword2<<endl;
  }

  word1.erase(word1.begin(), word1.begin()+2);
  word2.erase(word2.begin()+1, word2.begin()+4);

  i =1;
  j =1;
  for (pword1 = word1.begin(); pword1 != word1.end(); pword1++)
  {
    cout<<"word1["<<i++<<"]="<<*pword1<<endl;
  }

  for (pword2 = word2.begin(); pword2 != word2.end(); pword2++)
  {
    cout<<"word2["<<i++<<"]="<<*pword2<<endl;
  }
  

  return 1;
}
