#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <stdlib.h>

using namespace std;

/*
 *形参，一对迭代器，一个int型数据
 *功能，在此迭代器指示的范围内查找此int型数据，
  查找 成功，返回true，
       失败，返回false
 *
 * */

int ia[] = {1,2,3,4,5,6,7,8,9,10};
vector<int> ivec(ia, ia+10); 

bool find(vector<int>::iterator begin, vector<int>::iterator end, int k )
{
    for(; begin != end; begin++)
    {
        if (*begin == k)//find
        {
            return true;
        }        
    }
    return false;
}



int main(int argc, char **argv)
{
    vector<int>::iterator find_begin = ivec.begin(),
                          find_end = ivec.end();
    int key = atoi(argv[1]);
    if(find(find_begin, find_end, key))
    {
        cout<<"find success!"<<endl;
        return 0;
    }    
    cout<<"find failue!"<<endl;
    return 1;

}
