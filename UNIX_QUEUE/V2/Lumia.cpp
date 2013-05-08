#include <iostream>
#include "./lib/queue.h"
#include "./lib/msg.h"

using namespace std;

int main(int argc, char **argv)
{
    CQueue msgQue(5);
    #if 0
    if ( msgQue.IsQueueEmpty() == false )
    {
        cout<<"queue empty!"<<endl;
    }
    #endif
    CMsg msgObj1(TRAFFIC, 20);
    CMsg msgObj2(TRAFFIC, 30);
    CMsg msgObj3(TRAFFIC, 80);
    CMsg msgObj4(TRAFFIC, 70);
    CMsg msgObj5(TRAFFIC, 10);
    //CMsg *inMsg =  &msgObj;
    msgQue.InQueue(&msgObj1);
    cout<<"msgObj1 in queue success!"<<endl;
    msgQue.InQueue(&msgObj2);
    cout<<"msgObj2 in queue success!"<<endl;
    msgQue.InQueue(&msgObj3);
    cout<<"msgObj3 in queue success!"<<endl;
    msgQue.InQueue(&msgObj4);
    cout<<"msgObj4 in queue success!"<<endl;
    msgQue.InQueue(&msgObj5);
    cout<<"msgObj5 in queue success!"<<endl;
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
    }
    else
        cout<<"outQueue faile!"<<endl;
    return 1;
}

