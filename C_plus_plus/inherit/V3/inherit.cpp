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
    //virtual ~CBrass()
    ~CBrass()
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
    //virtual ~CBrassPlus()
    ~CBrassPlus()
    {
        cout<<"CBrassPlus<Destructor>:"<<"c="<<this->c<<endl;
    }
};

/*
 *if we didn't use virtual destructor, it will a problem.
 * */
int main(int argc, char **argv)
{
    /*
 *    not use virtual, so when delete pBrass, it call the destructor, but which one will be invoked?
 *    the pointer type or the pointer aim the object type.
 *    the answer is clear: if you not use the virtual, then it just call the pointer type 's destructor. 
 *  */
    CBrass *pBrass = new CBrassPlus(11, 22, 33); 
    delete pBrass;
    return 1;
}
