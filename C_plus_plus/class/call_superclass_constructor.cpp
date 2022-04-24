#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
    Weapon()
    {
        cout << "Weapon constructor" << endl;
    }

    Weapon(int value, string name) : m_value(value), m_name(name)
    {
        cout << "Weapon constructor"
            << ", value is: " << m_value
            << ", name is: " << m_name
            << endl;
    }

    virtual ~Weapon()
    {
        cout << "Weapon destructor" << endl;
    }
private:
    int m_value;
    string m_name;
};


class Sold : public Weapon {
public:
    Sold(float damage) : m_damage(damage) , Weapon(10, "killer") {
        cout << "Sold constructor"
            << ", damage is: "
            << m_damage
            << endl;
    }

    virtual ~Sold()
    {
        cout << "Sold destructor" << endl;
    }
private:
    float m_damage;
};

int main()
{
    Sold sold(27.8);
    return 0;
}