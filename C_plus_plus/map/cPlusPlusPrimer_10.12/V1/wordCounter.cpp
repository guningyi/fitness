#include<map>
#include<utility>
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char **argv)
{
    map<std::string, int> wordCount;
    string wordText;
    while((cin>>wordText) && (wordText != "exit"))
    {
        pair< map<std::string, int>::iterator , bool > ret = 
            wordCount.insert(make_pair(wordText,1));
        if(!ret.second)
            ++ret.first->second;
    }
    map<std::string, int>::iterator iterMap = wordCount.begin();
    while(iterMap != wordCount.end())
    {
        cout<<iterMap->first<<": appear ("<<iterMap->second<<") times"<<endl;
        iterMap++;
    }
    
    return 0;
}
