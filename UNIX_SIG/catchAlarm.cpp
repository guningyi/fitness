#include <iostream>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


using namespace std;

static int alarm_fired = 0;

void ding(int sig)
{
    alarm_fired = 1;
}


 

int main(int argc, char **argv)
{
    pid_t pid;
    cout<<"alarm application starting!"<<endl;
 
    pid = fork();
    switch(pid)
    {
        case -1:
          cout<<"fork error!"<<endl;
          //exit(1);
          return 1;
        case 0:
          sleep(5);
          kill(getpid(), SIGALRM);
          //exit(0);
          return 0;
    }
    
    cout<<"waiting for alarm to go off"<<endl;
    (void) signal(SIGALRM, ding);

    pause();
    if (alarm_fired)
        cout<<"Ding!"<<endl;
    cout<<"Done!"<<endl;
    //exit(0);
    return 0;


}
