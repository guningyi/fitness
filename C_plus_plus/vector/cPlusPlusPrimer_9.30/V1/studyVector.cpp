#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> ivec;
    cout<<"ivec's size is:"<<ivec.size()<<endl;
    cout<<"ivec's capacity is:"<<ivec.capacity()<<endl;

    cout<<"-----------insert 24 elements------------"<<endl;
    for(vector<int>::size_type ix = 0; ix != 24; ix++)
    {
        ivec.push_back(ix);
    }
    cout<<"ivec's size is:"<<ivec.size()<<endl;
    cout<<"ivec's capacity is:"<<ivec.capacity()<<endl;

    cout<<"-----------use container reserve------------"<<endl;
    ivec.reserve(50);
    cout<<"ivec's size is:"<<ivec.size()<<endl;
    cout<<"ivec's capacity is:"<<ivec.capacity()<<endl;

    cout<<"-----------use full ivec------------"<<endl;
    while(ivec.size() != ivec.capacity())
        ivec.push_back(0);
    cout<<"ivec's size is:"<<ivec.size()<<endl;
    cout<<"ivec's capacity is:"<<ivec.capacity()<<endl;

    cout<<"-----------add just one element into the full ivec------------"<<endl;
    ivec.push_back(0);
    cout<<"ivec's size is:"<<ivec.size()<<endl;
    cout<<"ivec's capacity is:"<<ivec.capacity()<<endl;


    return 0;
}
