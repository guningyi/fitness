#include <list>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    list<int> ilist1, ilist2;
    int aa[] = {1,2,3,4,5,6,7,8,9,10};
    list<int>::iterator iterList1 = ilist1.begin(),
                        iterList2 = ilist2.begin();
    ilist1.insert(iterList1, 33);
    ilist1.insert(iterList1,aa, aa+7);
    for (; iterList1 != ilist1.end(); iterList1++)
    {
        cout<<*iterList1<<endl;
    }
    return 0;
}
