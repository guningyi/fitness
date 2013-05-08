#include<pthread.h>
#include "comm.h"
using namespace std;

struct foo{
    int a, b, c, d;
};


void 
printfoo(const char*s, const struct foo* fp)
{
    cout<<s<<endl;
    cout<<"structure at 0x"<<(unsigned)fp<<endl;
    cout<<"foo.a=:"<<fp->a<<endl;
    cout<<"foo.b=:"<<fp->b<<endl;
    cout<<"foo.c=:"<<fp->c<<endl;
    cout<<"foo.d=:"<<fp->d<<endl;
}

void*
thr_fn1(void *arg)
{
    struct foo foo = {1,2,3,4};
    cout<<"thread1"<<&foo<<endl;
    pthread_exit((void *)&foo);
}

void*
thr_fn2(void *arg)
{
    cout<<"thread2 ID is:"<<pthread_self()<<endl;
    pthread_exit((void*)0);
}

int main(int argc, char **argv)
{
    int err;
    pthread_t tid1,tid2;
    struct foo *fp;
 
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0)
    {
        cout<<"can't create thread1,err is:"<<err<<endl;
    }

    err = pthread_join(tid1, (void *)&fp);
    if (err != 0 )
    {
        cout<<"can't join with thread1, err is:"<<err<<endl;
    }
    sleep(1);
    cout<<"parent starting second thread"<<endl;

    err = pthread_create(&tid2,NULL, thr_fn2, NULL);
    if (err != 0)
    {
        cout<<"can't create thread2, err is:"<< err<<endl;
    }

    sleep(1);
    printfoo("parent:\n", fp);
    exit(0);

}


