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
    virtual void showInfo()
    {
        cout<<"I am CBrass->\n"<<"a = "<<a<<"\n"<<"b = "<<b<<endl;
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
    virtual void showInfo()
    {
        cout<<"I am CBrassPlus->\n"<<"c = "<<c<<endl;
    }
};


int main(int argc, char **argv)
{
    CBrass objBrass(1,2);
    CBrassPlus objBrassPlus(11,22,33);

    CBrass *pObjBrass = &objBrass;  
    CBrass *pObjBrassPlus = &objBrassPlus;
    
    pObjBrass->showInfo();  // use virtual to get the polymorphism
    pObjBrassPlus->showInfo(); //use virtual to get the polymorphism

    objBrass = objBrassPlus;
    objBrass.showInfo(); //polymorphism just use pointer and referance, aggigment obj will not present the polymorphism.
    return 1;
}
