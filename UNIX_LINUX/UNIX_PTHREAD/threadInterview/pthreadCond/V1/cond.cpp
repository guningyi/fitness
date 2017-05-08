#include <iostream>
#include <pthread.h>
#define TCOUNT 10 
#define COUNT_LIMIT 12 

using namespace std;

pthread_cond_t count_threshold_cv;
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void* routine1(void *arg)
{
    cout<<"I am routine 1"<<endl;
    while(count<TCOUNT)
    {
        pthread_mutex_lock(&mymutex);
        count++;
        if (count == COUNT_LIMIT)
        {
            pthread_cond_signal(&count_threshold_cv);
            cout<<"routine1:"<<"count="<<count<<"Threadhold reached!"<<endl;
        }
        pthread_mutex_unlock(&mymutex);
        cout<<"routine1:count="<<count<<"unlocking mutex"<<endl;
    }
    pthread_exit(NULL);
}

void *routine2(void *arg)
{
    cout<<"I am routine 2"<<endl;
    pthread_mutex_lock(&mymutex);
    if (count < COUNT_LIMIT)
    {
        pthread_cond_wait(&count_threshold_cv, &mymutex);
        cout<<"condition signal received!"<<endl;
    }
    pthread_mutex_unlock(&mymutex);
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t tid1, tid2;
    void* (*ptr1)(void*) = routine1;
    void* (*ptr2)(void*) = routine2;

    pthread_cond_init(&count_threshold_cv, NULL);

    pthread_create(&tid1, NULL,ptr1,NULL );
    pthread_create(&tid2, NULL,ptr2,NULL );

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_cond_destroy(&count_threshold_cv);
    //pthread_exit(NULL);   
    return 1;
}
