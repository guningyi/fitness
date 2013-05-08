#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
    vector<std::string> svec;
    svec.reserve(8);
    std::string textWord;
    while(cin>>textWord)
        svec.push_back(textWord);
    svec.resize(svec.size()+svec.size()/2);
    cout<<"svec's size is :"<<svec.capacity()<<endl;
    return 0;
}
