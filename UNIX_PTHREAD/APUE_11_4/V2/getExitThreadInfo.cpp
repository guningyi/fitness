#include<pthread.h>
#include "comm.h"
using namespace std;

void
cleanup(void *arg)
{
    cout<<"cleanup:"<<(char*)arg<<endl;
}



void*
thr_fn1(void *arg)
{
    char s1[] = "thread 1 first handler";
    char s2[] = "thread 1 second handler";
    cout<<"thread1 start!"<<endl;
    pthread_cleanup_push( cleanup, s1);
    pthread_cleanup_push(cleanup, s2);
    cout<<"thread1 push complete"<<endl;
    if (arg)
    {
        return ((void*)1);
    }
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return ((void*)1);
}

void*
thr_fn2(void *arg)
{
    char s1[] = "thread 2 first handler";
    char s2[] = "thread 2 second handler";
    cout<<"thread2 start!"<<endl;
    pthread_cleanup_push(cleanup, s1);
    pthread_cleanup_push(cleanup, s2);
    cout<<"thread2 push complete"<<endl;
    if (arg)
    {
        pthread_exit((void*)2);
    }
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void*)2);
}

int main(int argc, char **argv)
{
    int err;
    pthread_t tid1,tid2;
    void * tret;
 
    err = pthread_create(&tid1, NULL, thr_fn1, (void*)1);
    if (err != 0)
    {
        cout<<"can't create thread1,err is:"<<err<<endl;
    }
    err = pthread_create(&tid2, NULL, thr_fn2, (void*)1);
    if (err != 0)
    {
        cout<<"can't create thread2,err is:"<<err<<endl;
    }

    err = pthread_join(tid1, &tret);
    if (err != 0 )
    {
        cout<<"can't join with thread1, err is:"<<err<<endl;
    }
    cout<<"thread1 exit code:"<<(int)tret<<endl;

    err = pthread_join(tid2, &tret);
    if (err != 0 )
    {
        cout<<"can't join with thread2, err is:"<<err<<endl;
    }

    cout<<"thread1 exit code:"<<(int)tret<<endl;
    exit(0);

}


