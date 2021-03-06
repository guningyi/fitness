//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class Girl
{
  protected:
    char* m_name;
    int m_age;
  public:
    void init(char* _name, int _age)
    {
        m_name = _name;
        m_age = _age;
    }
    virtual void say()
    {
        printf("奴家%s, 年华%d", m_name, m_age);
    }
};

class Musicor
{
  public:
   virtual void play() = 0;
   #if 0
    virtual void play()
    {
        cout<<"hello"<<endl;
    }
   #endif
};
    
class XiaoQian: public Girl, public Musicor
{
  public:
    XiaoQian(int _age)
    {
        init("ABC", _age);
        //XiaoQian::m_name = "ABC";
        //XiaoQian::m_age = _age;
    }
    void say()
    {
        printf("我是%s, 今年%d岁", m_name, m_age);
        Girl::say();
    }
    
    void play()
    {
        printf("%d在弹琵琶", m_name);
    }
};
                        
void fx(Musicor* girl)
//void fx(Girl* girl)
{
    Girl* tmp = (Girl*)girl;
    //girl->say();
    tmp->say();
}

int main(int argc, char** argv)
{
    XiaoQian *girl = new XiaoQian(21);
    girl->say();
    cout<<"\n"<<endl;
    fx(girl);

    getchar();
    return 0;
}


