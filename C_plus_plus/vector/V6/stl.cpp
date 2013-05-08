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
    vector<int> ivec(0);
    //下标操作不能添加元素，因为下标只能获取已经存在的元素。
    //ivec此时是一个空的容器。
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix)
    {
        ivec[ix] = 20;
    } 
    


    return 0;

}
