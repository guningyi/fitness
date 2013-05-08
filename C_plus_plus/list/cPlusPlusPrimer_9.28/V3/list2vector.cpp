#include<list>
#include<vector>
#include<iostream>

using namespace std;


/*警告
   warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
 *
 * 表明编译器探察出，这样的使用方式可能会导致对静态存储区的字符常量的修改
 * 错误的解决方法： const char*
 *
 * 导致编译报错
 *
 *
 /usr/lib/gcc/i686-redhat-linux/4.6.3/../../../../include/c++/4.6.3/bits/stl_list.h:1456:6: error: invalid conversion from ‘const char*’ to ‘std::list<char*>::value_type {aka char*}’ [-fpermissive]
/usr/lib/gcc/i686-redhat-linux/4.6.3/../../../../include/c++/4.6.3/bits/stl_list.h:987:7: error:   initializing argument 1 of ‘void std::list<_Tp, _Alloc>::push_back(const value_type&) [with _Tp = char*, _Alloc = std::allocator<char*>, std::list<_Tp, _Alloc>::value_type = char*]’ [-fpermissive]

  */

int main(int argc, char **argv)
{
    //char ptrA[] = {"aaa"};
    //char ptrB[] = {"bbb"};
    //char ptrC[] = {"ccc"};
    //char *ptrChar[] = {ptrA, ptrB, ptrC};
    
    const char *ptrChar[] = {"aaa", "bbb", "ccc"};

    list<char *> clist(ptrChar, ptrChar+3);
    vector<std::string> svec;
    list<char *>::iterator iterList = clist.begin();
    vector<std::string>::iterator iterVec = svec.begin();
    for(;iterList != clist.end(); iterList++)
    {
        iterVec = svec.insert(iterVec, *iterList);
        cout<<*iterVec<<endl;
    } 
    return 0;
}
