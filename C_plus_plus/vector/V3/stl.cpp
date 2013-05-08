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
    vector <std::string> svec(30);
    list <int>  ilist(50);
#if 0
    if (svec.empty() != true || ilist.empty() != true )
    {
        cout<<"svec or ilist is not empty!"<<endl;
        return 0;
    }
#endif
    cout<<"svec's capacity is:"<<svec.capacity()<<endl;
    cout<<"svec's size is:"<<svec.size()<<endl;
    cout<<"ilist's size is:"<<ilist.size()<<endl;


    svec.push_back("is it ok?");
    

    return 1;

}
