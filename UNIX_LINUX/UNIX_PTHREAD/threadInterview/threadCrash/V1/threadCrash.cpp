#include <iostream>
#include <pthread.h>

using namespace std;

pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void* myProcess1(void *arg)
{
    pthread_t tid;
    tid = pthread_self();
    cout<<"myProcess1 tid is:"<<tid<<endl;
    pthread_mutex_lock(&mymutex);
    count = 1;
    cout<<"myProcess1 set count = "<<count<<endl;
    pthread_mutex_unlock(&mymutex);
    pthread_exit(NULL);
}

void* myProcess2(void *arg)
{
    pthread_t tid;
    tid = pthread_self();
    cout<<"myProcess2 tid is:"<<tid<<endl;
    pthread_mutex_lock(&mymutex);
    count = 2;
    cout<<"myProcess2 set count = "<<count<<endl;
    pthread_mutex_unlock(&mymutex);
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t tid1, tid2;
    void* (*process1)(void *arg) = myProcess1;
    void* (*process2)(void *arg) = myProcess2;
    int ret1 = pthread_create(&tid1,NULL,myProcess1,NULL);
    if (ret1 == 0)
    {
        cout<<"1"<<"\n"<<endl;
    }
    int ret2 = pthread_create(&tid2,NULL,myProcess2,NULL);
    if (ret2 == 0)
    {
        cout<<"2"<<"\n"<<endl;
    }
    sleep(3);
}
