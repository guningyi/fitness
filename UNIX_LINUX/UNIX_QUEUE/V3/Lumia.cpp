#include <iostream>
#include <string>
#include "./lib/queue.h"
#include "./lib/msg.h"

using namespace std;

int main(int argc, char **argv)
{
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
    if( msgQue.OutQueue() == true )
    {
        cout<<"OutQueue is ok!"<<endl;
    }
   
    msgQue.travelQueue();
    if ( msgQue.getCurrLength() != 0 )
    {
        const CMsg &retMsg = msgQue.getQueueMsg();
	CMsg tmp_ptr = retMsg;
        cout<<"outMsg->Type is : "<<tmp_ptr.getMsgType()<<endl;
        cout<<"outMsg->Data is : "<<tmp_ptr.getMsgData()<<endl;
        cout<<"outMsg->Info is : "<<tmp_ptr.getMsgInfo()<<endl;
        //CMsg *temp = &tmp_ptr;
        //delete &tmp_ptr;
    }
    else
        cout<<"outQueue faile!"<<endl;
    return 1;
}

