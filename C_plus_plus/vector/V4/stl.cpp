#include <string>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> ivec(10);
    vector<int>::iterator itarIvec = ivec.begin();
    for(; itarIvec != ivec.end(); itarIvec++)
    {
        cout<<"vector member is :"<<*itarIvec<<endl;
    }
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix)
    {
        ivec[ix] = 20;
    } 

    for(vector<int>::size_type ixx = 0; ixx != ivec.size(); ++ixx)
    {
        cout<<"reflush vector member is:"<< ivec[ixx]<<endl;
    }


    return 0;

}
