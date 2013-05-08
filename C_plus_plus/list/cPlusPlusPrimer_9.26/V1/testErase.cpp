#include<list>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    list<int> ilist(ia,ia+11);
    vector<int> ivec(ia,ia+11);
    list<int>::iterator iterList = ilist.begin();
    vector<int>::iterator iterVec = ivec.begin();
    while(iterList != ilist.end())
    {
        if (*iterList%2 != 0)//odd
        {
            iterList = ilist.erase(iterList);
            //ilist.erase(iterList);  segfault ,没有接收返回的迭代器，原来的迭代器失效
        }
        else
        {
            iterList++;
        }
    }
    while(iterVec != ivec.end())
    {
        if (*iterVec%2 == 0)//not odd
        {
            iterVec = ivec.erase(iterVec);
        }
        else
        {
            iterVec++;
        }
    }

    iterList = ilist.begin();
    iterVec = ivec.begin();
    cout<<"ilist after erase is:"<<endl;
    for(;iterList != ilist.end();iterList++)
    {
        cout<<*iterList<<endl;
    }
    cout<<"ivec after erase is:"<<endl;
    for(;iterVec != ivec.end();iterVec++)
    {
        cout<<*iterVec<<endl;
    }



    return 0;
}
