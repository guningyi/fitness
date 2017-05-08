#include <iostream>
#include <string>
#include "./lib/queue.h"
#include "./lib/msg.h"

using namespace std;

int main(int argc, char **argv)
{
    int i = 3;
    CQueue msgQue(5);
    CMsg msgObj1(TRAFFIC, 20, "hello world!");
    CMsg msgObj2(TRAFFIC, 30, "I will arrive at 3:00 AM");
    CMsg msgObj3(TRAFFIC, 80, "Let's play football!");
    CMsg msgObj4(TRAFFIC, 70, "did you recive my messages?");
    CMsg msgObj5(TRAFFIC, 10, "Jolly, if you receive this message, pls call me. Ivan");
    msgQue.InQueue(&msgObj1);
    msgQue.InQueue(&msgObj2);
    msgQue.InQueue(&msgObj3);
    msgQue.InQueue(&msgObj4);
    msgQue.InQueue(&msgObj5);
    
    msgQue.travelQueue();
    while( i > 0 )
    {
        if( msgQue.OutQueue() == true )
        {
            cout<<"OutQueue is ok!"<<endl;
        }
        else
        {
            return 0;
        } 
        i--;
    }
    msgQue.travelQueue();
    if ( msgQue.getCurrLength() != 0 )
    {
        const CMsg &retMsg = msgQue.getQueueMsg();
	CMsg tmp_ptr = retMsg;
        cout<<"outMsg->Type is : "<<tmp_ptr.getMsgType()<<endl;
        cout<<"outMsg->Data is : "<<tmp_ptr.getMsgData()<<endl;
        cout<<"outMsg->Info is : "<<tmp_ptr.getMsgInfo()<<endl;
    }
    else
        cout<<"outQueue faile!"<<endl;


    /* test operator+ */

    CMsg msgObj6(TRAFFIC, 1000, "Man");
    CMsg msgObj7(TRAFFIC, 1100, "and");
    CMsg msgObj8(TRAFFIC, 1200, "women");
    CMsg total;
    total.operator+(msgObj6);
    total.operator+(msgObj7);
    total.operator+(msgObj8);
    total.showCMsg();
    //msgObj6 = msgObj6 + msgObj7 + msgObj8;
    return 1;
}

