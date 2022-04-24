#include <vector>
#include <thread>
#include <iostream>
#include <algorithm>
#include <unistd.h>

using namespace std;

vector<int> g_vec;

void WriteVec()
{
    while (1) {
        g_vec.push_back(15);
        cout << "g_vec size:" << g_vec.size();
        sleep(5);
    }
}

void ReadVec()
{
    while (1) {
        for_each(g_vec.begin(), g_vec.end(), [&] (int s){
            cout << s << " ";
        });
        sleep(3);
    }
}

int main()
{
    thread tWrite(WriteVec);
    tWrite.detach();

    thread tRead(ReadVec);
    tRead.detach();

    thread tRead2(ReadVec);
    tRead2.detach();

    while (1) {

    }

    return 0;
}