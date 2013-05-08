#include <list>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int aa[] = {1,2,3,4,5,6,7,8,9,10};
    list<int> ilist(aa, aa+8);
    cout<<"ilist's size is :"<<ilist.size()<<endl;
    cout<<"ilist's max size is :"<<ilist.max_size()<<endl;
    
    ilist.resize(20);  
    cout<<"ilist resize(20):"<<ilist.size()<<endl;    
    list<int>::iterator iterList = ilist.begin();
    /*
 *  resize 之后，如果容器扩大，新增加的元素是在尾部
 * */
    for(;iterList != ilist.end(); iterList++)
    {
        cout<<*iterList<<endl;
    }

    /*
 *  resize 之后，如果容器缩小，被删除的元素是尾部起向前删除
 * */
    ilist.resize(2);
    iterList = ilist.begin();
    for(;iterList != ilist.end(); iterList++)
    {
        cout<<*iterList<<endl;
    }

    return 0;
}
