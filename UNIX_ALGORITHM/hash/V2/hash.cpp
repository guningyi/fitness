#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

using namespace std;



int hashSize[] = {11, 19, 29, 37,47}; //hash table size increase
int hashLength = 0; // length of hash table
int conflictNum;

CHashTable::CHashTable()
{
    int i;
    count = 0;
    size = 0;
    hashLength = hashSize[0];
    elem = new strElemType[hashLength];
    if (!elem)
    {
        cout<<"alloc memory faile!"<<endl;
        exit(0);
    }
    for(i=0; i < hashLength; i++)
    {
        elem[i].key = nullkey;
    }
    cout<<"CHashTable Constructor...!"<<endl;
}


CHashTable::~CHashTable()
{
    delete[]elem;
    elem = NULL;
    count = 0;
    size = 0;
    cout<<"CHashTable Destructor...!"<<endl;
}



unsigned int CHashTable::hash(KeyType k)
{
    return k%hashLength;
}


void CHashTable::collision(int &p, int d)
{
    p=(p+d)%hashLength;
}

bool CHashTable::searchHash(KeyType k, int &p)
{
    conflictNum = 0;
    p = hash(k);
    while((elem[p].key != nullkey) && (elem[p].key != k))
    {
        conflictNum++;
        if (conflictNum < hashLength)
        {
            collision(p, conflictNum);
        }
        else
            return false;
    }
    if (elem[p].key == k)
        return true;
    else
        return false;
}

int CHashTable::insertHash(strElemType e)
{
    int p;
    if (searchHash(e.key, p))
        return -1;
    else if(conflictNum < hashSize[size]/2)
    {
        elem[p] = e;
        count++;
        return 1; 
    }
    else
        reCreateHashTable();
    return 0;
}

void CHashTable::reCreateHashTable()
{
    int i, count2 = count;
    strElemType *p, *elem2 = new strElemType[count];
    p = elem2;
    cout<<"reCreate Hash Table!"<<endl;
    for(i=0; i < hashLength; i++)
    {
        if( elem[i].key != nullkey )
            *p++ = *(elem+i);
    }
    count = 0;
    delete []elem;
    size++;
    hashLength = hashSize[size];
    p = new strElemType[hashLength];

    if (!p)
    {
        cout<<"Alloc memory faile!"<<endl;
        exit(0);
    }

    elem = p;
    for(i=0; i<hashLength; i++)
    {
        elem[i].key = nullkey;
    }

    for(p=elem2; p<elem2+count2;p++)
    {
        insertHash(*p);
    }


}


void CHashTable::traveseHashTable()
{
    cout<<"Hash address"<<hashLength-1<<endl;
    for(int i = 0; i < hashLength; i++)
    {
        if(elem[i].key != nullkey)
            cout<<"Elem's key value is :"<<elem[i].key<<"  "<<"Elem's lable is:"<<elem[i].ord<<endl;
    }
}

void CHashTable::getData(int p)
{
    cout<<"Elem's key value is :"<<elem[p].key<<"  "<<"Elem's lable is:"<<elem[p].ord<<endl;
}



