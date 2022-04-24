#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    vec.resize(5);

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);

    for (auto item : vec) {
        cout << item << endl;
    }

    return 0;
}