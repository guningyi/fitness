#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

struct Msg {
    string m_msgName;
    int m_value;
};

vector<Msg> GenerateMsg()
{
    vector<struct Msg> msg;
    struct Msg msg1 = {"hello", 2};
    struct Msg msg2 = {"world", 3};
    struct Msg msg3 = {"time", 1};
    msg.push_back(msg1);
    msg.push_back(msg2);
    msg.push_back(msg3);
    return msg;
}

int Cmp(const struct Msg& a, const struct Msg& b)
{
    return a.m_value > b.m_value;
}

int main()
{
    vector<struct Msg> msg = GenerateMsg();
    sort(msg.begin(), msg.end(), Cmp);

    for (auto res : msg) {
        cout << res.m_msgName << " " << res.m_value << endl;
    }
    return 0;
}