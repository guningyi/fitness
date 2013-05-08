#include <iostream>
#include <signal.h>

using namespace std;

void catchSignal(int sig)
{
    cout<<"OK! I catch the signal :"<<sig<<endl;
    (void) signal(SIGINT, SIG_DFL);
}

int main(int argc, char **argv)
{
    (void) signal(SIGINT, catchSignal);
    while(1)
    {
        cout<<"Hello Ericsson!"<<endl;
        sleep(2);
    }
}

