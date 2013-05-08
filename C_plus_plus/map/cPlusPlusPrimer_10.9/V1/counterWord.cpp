#include<map>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
    map<std::string, int> wordCount;
    string wordText;
    while( (cin>>wordText) && (wordText != "exit"))
      ++wordCount[wordText];
    map<std::string, int>::iterator iterMap = wordCount.begin();
    while(iterMap != wordCount.end())
    {
        cout<<iterMap->first<<"  has appear:"<<iterMap->second<<" times"<<endl;
        iterMap++;
    }
    return 0;
}
