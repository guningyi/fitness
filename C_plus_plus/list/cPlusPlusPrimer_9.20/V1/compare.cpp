#include <list>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int aa[] ={1,2,3,4,5,6,7,8,9,10};
    vector<int> ivec(aa,aa+5);
    list<int>  ilist(aa,aa+8);
    vector<int>::iterator iterVec = ivec.begin();
    list<int>::iterator iterList = ilist.begin();
    while(iterVec != ivec.end() && iterList != ilist.end())
    {
        if (*iterVec != *iterList)
        {
            cout<<"Not equal!"<<endl;
            return 1;
        }
        iterVec++;
        iterList++;
    }
    if (iterVec == ivec.end() && iterList == ilist.end())
    {
        cout<<"Equal!"<<endl;
    }
    else
    {
       cout<<"Not equal!"<<endl;
    }
    return 0;
}
