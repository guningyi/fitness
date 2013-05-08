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
    //~CBrassPlus()
    {
        cout<<"CBrassPlus<Destructor>:"<<"c="<<this->c<<endl;
    }
};

/*
 *if we  use virtual destructor, then will do the complete destructor!
 * */
int main(int argc, char **argv)
{
    /*
 *    use virtual, so when delete pBrass, it call the complete destructor,
 *    
 *    first , it call the pointer aim to object's destructor.
 *    second, it up-trace the chain, call every declare the virtual destructor.
 *    so it will call CBrass's destructor.
 *  */
    CBrass *pBrass = new CBrassPlus(11, 22, 33); 
    delete pBrass;
    return 1;
}
