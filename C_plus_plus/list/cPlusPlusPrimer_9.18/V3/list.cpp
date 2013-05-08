/*
 *将奇数和偶数分到不同的deq中

这段程序有奇怪的问题，ilist的初始化是成功的，
但之后将奇数与偶数分别copy到deq1 deq2中后，
使用cout去输出结果来校验发现这两个deque容器的大小变大了。
第一个问题本身不是问题，是对push_back()的使用上有理解错误，
push_back()是指向容器的尾部插入元素，而ideq1,ideq2在初始化时
已经被设置成大小为10，每个元素都是0的容器了。
-------------------

直接在初始化时将ideq1,ideq2的大小设置为0即可。

第2个问题的修正，将ilist初始化时的范围设置为
ia,ia+10


 * */

#include <list>
#include <deque>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int ia[] = {1,2,3,4,5,6,7,8,9,10};
    list<int> ilist(ia, ia+10);//initial list container
    deque<int> ideq1(0),
               ideq2(0);
 
    cout<<"ilist size is:"<<ilist.size()<<endl;
    cout<<"ideq1 size is:"<<ideq1.size()<<endl;
    cout<<"ideq2 size is:"<<ideq2.size()<<endl;

    cout<<"\nlist data is :"<<endl;
    list<int>::iterator iterList = ilist.begin();
    for(;iterList != ilist.end(); iterList++)
    {
        cout<<*iterList<<endl;
        if( *iterList%2 == 0 )
        {
            ideq2.push_back(*iterList);
        }
        else //odd
        {
            ideq1.push_back(*iterList);
        }
    }
    cout<<"\nthe odd deq is:"<<endl;
    for (deque<int>::iterator iterDeq1 = ideq1.begin(); 
                              iterDeq1 != ideq1.end();
                              iterDeq1++)
    {
        cout<<*iterDeq1<<endl;
    }
 
    cout<<"the no-odd deq is:\n"<<endl;
    for (deque<int>::iterator iterDeq2 = ideq2.begin(); 
                              iterDeq2 != ideq2.end();
                              iterDeq2++)
    {
        cout<<*iterDeq2<<endl;
    }
 
    return 0;

}
