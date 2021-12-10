#include <iostream>

using namespace std;

// basic use.
template <typename ...args>
void Print(const args ...m)
{
    cout << sizeof ...(m) << endl;
}

void print()
{
    cout << "empty" << endl;
}

template <class T, class ...args>
void print(T head, args ...rest)
{
    cout << "parameters:" << head << endl;
    print(rest...);
}

int main(int argc, char **argv)
{
    Print(10,202);

    print(1, 2, 3, 4);
    return 0;
}