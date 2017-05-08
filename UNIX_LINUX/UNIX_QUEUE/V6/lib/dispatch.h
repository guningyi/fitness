#ifndef _DISPATCH_H_
#define _DISPATCH_H_


/*
 *create the dispatch 
 * */
class CQueue;
class CMsg;

class CDisPatch
{
friend class CQueue;
friend class CMsg;

public:
    CDisPatch();
    virtual ~CDisPatch();
private:
    CMsg *next;    
    int msgCount;
};



#endif 
