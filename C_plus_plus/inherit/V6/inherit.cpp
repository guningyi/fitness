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

class CBrassPlus:public CBrass
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

class CBrassAus: public CBrass
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
 * 编译会出问题，没有定义虚拟继承:
 * inherit.cpp:90:60: error: ‘CBrass’ is an ambiguous base of ‘CBrassMultiDrived’
 * 它的意思是：CBrassMultiDrived 所继承的 CBrass 不知道是来自 CBrassPlus 还是 CBrassAus.
 * 这就是因为没有使用虚拟继承的原因。
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
