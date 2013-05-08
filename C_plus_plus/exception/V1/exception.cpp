#include <iostream>

using namespace std;

int diff(int a, int b)
{
    if (a = -b)throw "bad augments: a = -b";
    return a/(a+b);
}

int main(int argc, char**argv)
{
    int tempA, tempB;
    //tempA=argv[1];
    //tempB=argv[2];
    tempA=100;
    tempB=-100;
    try{
        diff(tempA, tempB);
    }
    catch(const char* s)
    {
        cout<<s<<endl;
        cout<<"We catch the exception!"<<endl;
    }
    return 1;
}

