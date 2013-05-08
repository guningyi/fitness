/*
 *这样的函数会有严重的问题
 *假如我们要寻找一个并不在容器中的元素，此时返回的值是一个迭代器，
  但这个迭代器在做解引用操作后的值是不确定的.
 * */



#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <stdlib.h>

using namespace std;

int ia[] = {1,2,3,4,5,6,7,8,9,10};
vector<int> ivec(ia, ia+10); 

/*
 *形参，一对迭代器，一个int型数据
 *功能，在此迭代器指示的范围内查找此int型数据，
  查找 成功，返回指向该元素的迭代器
       失败，返回容器的最后一个原素的后一个位置
 *
 * */


vector<int>::iterator 
find(vector<int>::iterator begin, vector<int>::iterator end, int k )
{
    for(; begin != end; begin++)
    {
        if (*begin == k)//find
        {
            break;
        }        
    }
    //if end is the container's end. we just return end
    //else end is not the container's end,how we find the real end???
    return begin;
}



int main(int argc, char **argv)
{
    vector<int>::iterator find_begin = ivec.begin(),
                          find_end = ivec.end(),
                          find_return;
    if (argc < 2)
    {
        cout<<"Input parameter error!"<<endl;
        return 1;
    }
    int key = atoi(argv[1]);
    find_return = find(find_begin, find_end, key);
    cout<<*find_return<<endl; //当欲查找的元素不在容器中时，返回的是指向ivec.end()的迭代器，内容为0
    return 1;

}
