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
    //~CBrass()
    {
        cout<<"CBrass<Destructor>:"<<"a="<<this->a<<" "<<"b="<<this->b<<endl;
    }
    //virtual void showMember() = 0;
    void showMember()
    {
        cout<<"CBrass::showMember()-"<<"a= "<<a<<"\n"<<"b= "<<b<<endl;
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
    //~CBrassPlus()
    {
        cout<<"CBrassPlus<Destructor>:"<<"c="<<this->c<<endl;
    }
    //virtual void showMember()
    void showMember()
    {
        cout<<"CBrassPlus::showMember()-"<<"c= "<<c<<endl;
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
    //virtual void showMember()
    void showMember()
    {
        cout<<"CBrassAus::showMember()-"<<"d= "<<d<<endl;
    }
};



class CBrassMultiDrived :  public CBrassPlus ,  public CBrassAus
{
  private:
    int e;
  public:
    CBrassMultiDrived(int pa, int pb, int pc, int pd, int pe):CBrass(pa, pb),CBrassPlus(pa, pb, pc), CBrassAus(pa, pb, pd)
    {
        e = pe;
        cout<<"CBrassMultiDrived<Constructor>:"<<"e="<<e<<endl;
    }
    virtual ~CBrassMultiDrived()
    {
        cout<<"CBrassMultiDrived<Destructor>:"<<"e="<<this->e<<endl;
    }
    //virtual void showMember()
    void showMember()
    {
        cout<<"CBrassMultiDrived::showMember()-"<<"e= "<<e<<endl;
    }

};


/*
 * multipul drived class
 * */
int main(int argc, char **argv)
{
    CBrass *pBrass = new CBrassMultiDrived(11, 22, 33,44,55);
    /*
 *  没有定义virtual方法，应该是根据指针类型来调用方法。 
 *  pBrass指针调用的应该是 CBrass::showMember()函数.
 *    
 * */
    pBrass->showMember(); 
    delete pBrass;
    return 1;
}
