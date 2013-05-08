#ifndef _HASH_H_
#define _HASH_H_

typedef int KeyType;
const int nullkey = 0; // mark this posistion is NULL
//int conflictNum; //count the number of conflict

struct strElemType
{
    KeyType key;
    int ord;    
};


//int hashSize[] = {11, 19, 29, 37,47}; //hash table size increase
//int hashLength = 0; // length of hash table

class CHashTable
{
private:
  strElemType *elem;  
  int count; //current data number
  int size;  //
public:
  CHashTable();
  virtual ~CHashTable();
  unsigned hash(KeyType k);
  void collision(int &p, int d);
  bool searchHash(KeyType k, int &p);
  int insertHash(strElemType e);
  void reCreateHashTable();
  void traveseHashTable();
  void getData(int p);
};



#endif
