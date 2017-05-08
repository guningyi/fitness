#include<pthread.h>
#include "comm.h"
using namespace std;


void*
thr_fn1(void *arg)
{
    cout<<"thread1 returning!"<<endl;
    return((void*)1);
}

void*
thr_fn2(void *arg)
{
    cout<<"thread2 exiting!"<<endl;
    pthread_exit((void*)2);
}

int main(int argc, char **argv)
{
    int err;
    pthread_t tid1,tid2;
    void *tret;
    
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0)
    {
        cout<<"can't create thread1,err is:"<<err<<endl;
    }

    err = pthread_create(&tid2,NULL, thr_fn2, NULL);
    if (err != 0)
    {
        cout<<"can't create thread2, err is:"<< err<<endl;
    }

    err = pthread_join(tid1, &tret);
    if (err != 0 )
    {
        cout<<"can't join with thread1, err is:"<<err<<endl;
    }

    cout<<"thread 1 exit code:"<<(int)tret<<endl;
    err = pthread_join(tid2, &tret);
    if (err != 0 )
    {
        cout<<"can't join with thread2, err is:"<<err<<endl;
    }

    cout<<"thread 2 exit code:"<<(int)tret<<endl;
    exit(0);

}


