#include <utility>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    typedef pair<std::string, int> input;
    vector<input> pvec;
    input word, word1;
    string textWord;
    int    num,count = 0;
    while((cin>>textWord>>num) && (textWord != "exit"))
    {    
        word = make_pair(textWord, num);
        pvec.push_back(word);
    }    
    vector<input>::iterator iterVec = pvec.begin();
    for(;iterVec != pvec.end(); iterVec++)
    {
        word1 = *iterVec;
        cout<<word1.first<<" "<<word1.second<<endl;
        //cout<<*iterVec.first<<" "<<*iterVec.second<<endl;
    }
    return 0;
}
