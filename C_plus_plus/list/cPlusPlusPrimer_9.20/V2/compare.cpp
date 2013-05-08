#include <list>
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv)
{
    if (argc < 5 )
    {
        cout<<"Input error!"<<endl;
        return 1;
    }
    int aa[] ={1,2,3,4,5,6,7,8,9,10};
    int ivecBegin = atoi(argv[1]);
    int ivecEnd = atoi(argv[2]);
    int ilistBegin = atoi(argv[3]);
    int ilistEnd = atoi(argv[4]);
   
    vector<int> ivec(aa+ivecBegin,aa+ivecEnd);
    list<int>  ilist(aa+ilistBegin,aa+ilistEnd);
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
