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
 * 新定义一个魔法效果类，其可以作用于英雄，改变英雄的状态。
 * 也就是其必须要访问英雄的private成员。
 * 提前定义编译出错。
 * */
#if 0
class CHero;
class CEffect
{
  private:
    int effectAttack;
    int effectDefense;
  public:
    CEffect(int attk, int def):effectAttack(attk), effectDefense(def){};
    virtual ~CEffect(){}
    void effectHero(CHero& hero)
    {
       hero.modifyAttack(effectAttack);
       hero.modifyDefense(effectDefense); 
    }
};
#endif
class CHero
{
  friend class CSword;
  friend class CArmour;
  friend class CEffect;
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
    void modifyAttack(int attk)
    {
        heroAttack += attk;
    }
    void modifyDefense(int def)
    {
        heroDefense+= def;
    }

};


class CEffect
{
  private:
    int effectAttack;
    int effectDefense;
  public:
    CEffect(int attk, int def):effectAttack(attk), effectDefense(def){};
    virtual ~CEffect(){}
#if 0
    void effectHero(CHero& hero)
    {
       hero.modifyAttack(effectAttack); //此处只是调用了CHero的公有方法去修改CHero的私有成员，不需要友元关系就可以做到。
       hero.modifyDefense(effectDefense);
    }
#endif
    void effectHero(CHero& hero)//直接访问CHero中的私有成员,利用友元关系。如果在CHero中没有声明CEffect类为其友元类，则编译出错。
    {
       hero.heroAttack += effectAttack;
       hero.heroDefense += effectDefense;
    }
};

#if 0
/*
 * 定时器类，为所有模块提供定时器支持。
 * 但是功能完善的定时器类要考虑较多的问题，我们将独立定义一个定时器章节来研究。
 * 不在友元这个环节来讲述。
 * */
class CTimer
{
  private:
    int elapse;
  public:
    CTimer(int elapse, (void*)func(void*))
    {
      
    }
    virtual ~CTimer()
    {

    }

};
#endif

int main(int argc, char **argv)
{
    CSword dragonSlayer(1000);
    CArmour goldenArmour(3000);

    CHero adam("adam", 500, 700);
    adam.getSword(dragonSlayer);
    adam.getArmour(goldenArmour);

    CEffect ef(30, -30);
    ef.effectHero(adam);
    adam.showHeroInfo();
    return 1;
}
