#include <iostream>

using namespace std;

class GPU {
public:
    GPU(int id) : m_gpuId(id)
    {
        cout << "GPU" << endl;
    }
private:
    int m_gpuId;
};

class Memory {
public:
    Memory(int mem) : m_memSize(mem)
    {
        cout << "Memory" << endl;
    }
private:
    int m_memSize;
};

class DeviceManager {
public:
    DeviceManager()
    {
        cout << "DeviceManager" << endl;
    }
private:
    GPU m_gpu{2};
    Memory m_memory{3};
};

int main()
{
    DeviceManager deviceManager;
    return 0;
}