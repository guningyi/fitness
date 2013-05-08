#include "operator.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char **argv)
{
    CMsg msg(10, "We test this operator!");
    cout<<msg;

    /*
 *   test operator new and delete
 * */
    //char buf[sizeof(CMsg)];
    void *p;
    CMsg* msg1 =  new CMsg(20, "test operator new and delete");


    return 1;
}


