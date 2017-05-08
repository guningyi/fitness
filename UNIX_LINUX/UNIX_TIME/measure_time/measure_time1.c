#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct timeval tpstart , tpend;
    float  timeuse;
    gettimeofday(&tpstart, NULL);
    sleep(100);
    gettimeofday(&tpend, NULL);
    timeuse = tpend.tv_sec - tpstart.tv_sec;
    printf("time use is: %f min\n", timeuse/60);
    return 1;
}
