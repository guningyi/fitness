#include<list>
#include<vector>
#include<iostream>

using namespace std;


/*警告
   warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
 *
 * 表明编译器探察出，这样的使用方式可能会导致对静态存储区的字符常量的修改
 * 消除告警的方法： 使用数组存贮字符串，因为数组中的内容是存储在桟中。编译器不会告警.
 *
 *
 *
  */

int main(int argc, char **argv)
{
    char ptrA[] = {"aaa"};
    char ptrB[] = {"bbb"};
    char ptrC[] = {"ccc"};
    char *ptrChar[] = {ptrA, ptrB, ptrC};
    

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
