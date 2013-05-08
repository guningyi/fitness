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
    virtual ~CBrassPlus()
    //~CBrassPlus()
    {
        cout<<"CBrassPlus<Destructor>:"<<"c="<<this->c<<endl;
    }
};

/*
 *if basic class didn't declare the virtual destructor. but public derived class declare  the virtual destructor, what will happen??
 * */
int main(int argc, char **argv)
{
    /*
 *   when delete the pBrass, it will call the CBrass's destructor, 
 *   then it will core dump 
 *    
 *    
 *    
 *    
 *  */
    CBrass *pBrass = new CBrassPlus(11, 22, 33); 
    delete pBrass;
    return 1;
}
