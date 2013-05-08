#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main(int argc, char **argv)
{
    strElemType r[12]={{17,1},{60,2},{29,3},{38,4},{1,5},{2,6},{3,7},{4,8},{5,9},{6,10},{7,11},{8,12}}; 
    int i, p, j;
    KeyType k;
    CHashTable H; //create object
    for(i = 0; i < 11; i++)
    {
        j = H.insertHash(r[i]);
        if (j == -1)
        {
            cout<<"The record :["<<r[i].key<<" "<<r[i].ord<<"]"<<"has been exist in Table"<<endl;
        }
    }

    cout<<"Traverse hash table by odd of address"<<endl;
    H.traveseHashTable();
    cout<<endl;

    cout<<"Pls input the key value of record the you want to search!"<<endl;

    cin>>k;
    j = H.searchHash(k, p);
    if (j == 1)
        H.getData(p);
    else
        cout<<"No such record!"<<endl;

    j = H.insertHash(r[11]);
    if ( j == 0 )
    {
        cout<<"Insert faile!"<<endl;
        cout<<"You have to reCreate the hash table!"<<endl;
        cout<<"reCreate the hash table......."<<endl;
        H.reCreateHashTable();
        H.insertHash(r[i]);
    }
    
    cout<<"Traverse the reCreate hash table!"<<endl;
    H.traveseHashTable();
    cout<<endl;

    cout<<"Pls input the key value of record the you want to search!"<<endl;
    cin>>k;
    j = H.searchHash(k, p);
    if ( j == 1 )
        H.getData(p);
    else
        cout<<"No such record!"<<endl;

    cout<<"Destory Hash Table!"<<endl;
    return 0;
}
