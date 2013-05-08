#include <iostream>
#include <string>

using namespace std;

class CBrass
{
  private:
    int a;
    int b;
  public:
    CBrass(int pa, int pb)
    {
        a = pa;
        b = pb;
        cout<<"CBrass<Contructor>:"<<"a="<<a<<" "<<"b="<<b<<endl;
    } 
    virtual ~CBrass()
    {
        cout<<"CBrass<Destructor>:"<<"a="<<this->a<<" "<<"b="<<this->b<<endl;
    }
   
};

class CBrassPlus:virtual public CBrass
{
  private:
    int c;
  public:
    CBrassPlus(int pa, int pb, int pc):CBrass(pa, pb)
    {
        c = pc;
        cout<<"CBrassPlus<Constructor>:"<<"c="<<c<<endl;
    }  
    virtual ~CBrassPlus()
    {
        cout<<"CBrassPlus<Destructor>:"<<"c="<<this->c<<endl;
    }
};

class CBrassAus: virtual public CBrass
{
  private:
    int d;
  public:
    CBrassAus(int pa, int pb, int pd):CBrass(pa, pb)
    {
        d = pd;
        cout<<"CBrassAus<Constructor>:"<<"d="<<d<<endl;
    }  
    virtual ~CBrassAus()
    {
        cout<<"CBrassAus<Destructor>:"<<"d="<<this->d<<endl;
    }
};



class CBrassMultiDrived :  public CBrassPlus ,  public CBrassAus
{
  private:
    int e;
  public:
    /*
 *  inherit.cpp:64:107: error: no matching function for call to ‘CBrass::CBrass()’
 *  编译出错， 因为类已经定义了虚拟继承，所以构造函数的使用规则已经发生了改变。
 *  编译器在检测到使用虚拟继承时会 禁止信息通过中间类自动传递给基类。
 *  必须显式的调用基类的构造函数传递信息
 *  CBrassMultiDrived(int pa, int pb, int pc, int pd, int pe):CBrass(pa, pb),CBrassPlus(pa, pb, pc), CBrassAus(pa, pb, pd)
 * */
    CBrassMultiDrived(int pa, int pb, int pc, int pd, int pe):CBrassPlus(pa, pb, pc), CBrassAus(pa, pb, pd)
    {
        e = pe;
        cout<<"CBrassMultiDrived<Constructor>:"<<"e="<<e<<endl;
    }
    virtual ~CBrassMultiDrived()
    {
        cout<<"CBrassMultiDrived<Destructor>:"<<"e="<<this->e<<endl;
    }

};


/*
 * multipul drived class
 *
 * */
int main(int argc, char **argv)
{
    /*
 *   when delete the pBrass, it will call the CBrass's destructor, 
 *  */
    //CBrass *pBrass = new CBrassPlus(11, 22, 33); 
    CBrass *pBrass = new CBrassMultiDrived(11, 22, 33,44,55); 
    delete pBrass;
    return 1;
}
