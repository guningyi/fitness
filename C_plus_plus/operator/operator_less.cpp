#include <map>
#include <iostream>
#include <cstdint>
 
template<typename T1, typename T2>
class Order {
public:
    Order(T1 value, T2 mount) : m_value(value), m_mount(mount) {}
    virtual ~Order() {}
 
    bool operator <(const Order& order) const {
        if ((order.m_value < m_value)
            || (order.m_value == m_value) && (order.m_mount < m_mount)) {
            return false;
        }

        return true;
    }
 
    T1 getValue() const
    {
        return m_value;
    }
 
    T2 getMount() const
    {
        return m_mount;
    }
 
private:
    T1 m_value;
    T2 m_mount;
};
 
int main()
{
    std::map<Order<float, uint64_t>, int> orderQueue;
    Order<float, uint64_t> order_1(16.29, 20000);
    Order<float, uint64_t> order_2(16.22, 10000);
    orderQueue.insert({order_1, 15});
    orderQueue.insert({order_2, 17});
 
    for (auto o : orderQueue) {
        std::cout << o.first.getValue() << std::endl;
    }
 
    std::map<Order<uint32_t, uint64_t>, int> orderQueue2;
    Order<uint32_t, uint64_t> order_3(16, 20000);
    Order<uint32_t, uint64_t> order_4(17, 10000);
    orderQueue2.insert({order_3, 19});
    orderQueue2.insert({order_4, 20});
 
    for (auto o : orderQueue2) {
        std::cout << o.first.getValue() << std::endl;
    }
    return 0;
}
