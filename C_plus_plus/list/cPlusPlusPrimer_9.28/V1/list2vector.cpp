#include<list>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
    char *ptrChar[] = {"aaa", "bbb", "ccc"};
    list<char *> clist(ptrChar, ptrChar+3);
    vector<std::string> svec;
    list<char *>::iterator iterList = clist.begin();
    vector<std::string>::iterator iterVec = svec.begin();
    for(;iterList != clist.end(); iterList++, iterVec++)
    {
        svec.push_back(*iterList);
        //cout<<*iterList<<endl;
        cout<<*iterVec<<endl;
    } 
    return 0;
}
