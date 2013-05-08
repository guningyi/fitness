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

    cout<<"we use count to check our program"<<endl;
    cout<<"please input the word that you want to check......."<<endl;
    while(cin>>wordText)
    {
        cout<<wordText<<"is appear ("<<wordCount.count(wordText)<<") times"<<endl;
    }



    
    return 0;
}
