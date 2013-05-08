#include<list>
#include<vector>
#include<iostream>

using namespace std;


/*此版本会出现三个警告
  list2vector.cpp:9:43: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
  list2vector.cpp:9:43: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
  list2vector.cpp:9:43: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
 *
 * 表明编译器探察出，这样的使用方式可能会导致对静态存储区的字符常量的修改
 * */

int main(int argc, char **argv)
{
    char *ptrChar[] = {"aaa", "bbb", "ccc"};
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
