#include <iostream>
#include <string>

using namespace std;


class CSword
{
  private:
    int attack;
  public:
    CSword(int atk):attack(atk){}
    virtual ~CSword(){}
    int getAttack(){return attack;}
};

class CArmour
{
  private:
    int defense;
  public:
    CArmour(int def):defense(def){}
    virtual ~CArmour(){}
    int getDefense(){return defense;}
};

/*
 *定义了剑和盔甲两个道具类，这两个类和英雄类不满足is-a关系，也不适合使用has-a关系，
  这里将其声明为英雄类的友元类。
 *
 * */
class CHero
{
  friend class CSword;
  friend class CArmour;
  private:
    int heroAttack;
    int heroDefense;
    std::string heroName;  
  public:
    CHero(std::string name,  int attk, int def)
    {
        heroAttack = attk;
        heroDefense = def;
        heroName = name;
        cout<<heroName<<" is here!"<<endl;
    }
    virtual ~CHero()
    {
        
        cout<<heroName<<" is dead!"<<endl;
    }
    void getSword(CSword& sw)
    {
        heroAttack += sw.getAttack();
        cout<<"Adam get the sword!"<<endl;
        cout<<"it supply ["<<sw.getAttack()<<"] attack power!"<<endl;
    }
    void discardSword(CSword& sw)
    {
        heroAttack -= sw.getAttack();
        cout<<"Adam discard the sword!"<<endl;
        cout<<"he loss ["<<sw.getAttack()<<"] attack power!"<<endl;
    }
    void getArmour(CArmour& am)
    {
        heroDefense += am.getDefense();
        cout<<"Adam get the armour!"<<endl;
        cout<<"it supply ["<<am.getDefense()<<"] defense power!"<<endl;
    }
    void discardArmour(CArmour& am)
    {
        heroDefense -= am.getDefense();
        cout<<"Adam discard the armour!"<<endl;
        cout<<"he loss ["<<am.getDefense()<<"] defense power!"<<endl;
    }
    void showHeroInfo()
    {
        cout<<"Name is:"<<heroName<<endl;
        cout<<"Attack is:"<<heroAttack<<endl;
        cout<<"Defense is:"<<heroDefense<<endl;
    }


};

int main(int argc, char **argv)
{
    CSword dragonSlayer(1000);
    CArmour goldenArmour(3000);

    CHero adam("adam", 500, 700);
    adam.getSword(dragonSlayer);
    adam.getArmour(goldenArmour);
    adam.showHeroInfo();
    return 1;
}
