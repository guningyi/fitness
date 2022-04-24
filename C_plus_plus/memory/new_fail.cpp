#include <iostream>

using namespace std;

const uint64_t MAX_SIZE = 100000000000;

struct GPU {
    string m_name;
    uint64_t m_serialNumber;
};

int main()
{
    struct GPU* pGpu = nullptr;
    try {
        pGpu = new GPU[MAX_SIZE];
    } catch (const std::bad_alloc& e) {
        cout << e.what() << endl;
    }

    if (pGpu == nullptr) {
        cout << "pGpu1 new fail!" << endl;
    }

    // crash
    struct GPU* pGpu2 = new GPU[MAX_SIZE];
    if (pGpu2 == nullptr) {
        cout << "pGpu2 new fail!" << endl;
    }

    return 0;
}