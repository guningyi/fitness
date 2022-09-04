#include <vector>
#include <iostream>

using namespace std;

struct VecWrapper {
    std::vector<unsigned int> m_vec;
};

struct VecLightWrapper {
    std::vector<unsigned int>* m_vecAddress;
};

void Print(void* data)
{
    std::cout << ((VecWrapper*)data)->m_vec.size() << std::endl;
}

void Print2(void* data)
{
    std::cout << (((VecLightWrapper*)data)->m_vecAddress)->size() << std::endl;
}

void* Print3(void* data)
{
    std::cout << (*((std::vector<unsigned int>*)data)).size() << std::endl;
    (*((std::vector<unsigned int>*)data)).push_back('e');
    (*((std::vector<unsigned int>*)data)).push_back('f');
    return data;
}

int main()
{
    std::vector<unsigned int> vec;
    vec.push_back('a');
    vec.push_back('b');
    vec.push_back('c');
    vec.push_back('d');
    struct VecWrapper vecWrapper;
    vecWrapper.m_vec = vec;
    Print(&vecWrapper);

    // 结构体包含了vector的首地址
    struct VecLightWrapper vecWrapper2;
    vecWrapper2.m_vecAddress = &vec;
    Print2(&vecWrapper2);

    // 直接使用vector的首地址，（vector的首地址是存在栈上，&vec）
    // (vector的数据是存在堆区， &vec[0])
    void* m = Print3((void*)&vec);
    for (auto elem : (*((std::vector<unsigned int>*)m))) {
        std::cout << "elem: " << elem << "\n" << std::endl;
    }
    return 0;
}