#include "typedef.h"
#include "Statblock.h"
#include "PointWell.h"
#include <memory>
#include <string>

#ifndef PlayerCharacterDelegate_H
#define PlayerCharacterDelegate_H

class PlayerCharacterDelegate : public StatBlock{
public:
    static const experience_type LEVEL_2_AT = 100u;
    static const experience_type LEVEL_SCALAR = 2u; // multiplier for exp requirements

    PlayerCharacterDelegate() : StatBlock(0u, 0u, 0u){
        current_level = 1u;
        current_exp = 0u;
        exp_to_next_level = LEVEL_2_AT;
        // HP = std::unique_ptr<PointWell>(new PointWell());
        HP = std::make_unique<PointWell>();
    }

    void gainEXP(experience_type gained_exp){
        current_exp += gained_exp;
        while (check_if_leveled()){}
    }

    level_type getLevel() {
        return current_level;
    }

    experience_type getCurrentEXP(){
        return current_exp;
    }

    experience_type getEXPToNextLevel(){
        return exp_to_next_level;
    }

    virtual void LevelUp() = 0;
    virtual std::string getClassName() = 0;

    std::unique_ptr<PointWell> HP;

protected:
    level_type current_level;
    experience_type current_exp;
    experience_type exp_to_next_level;

    bool check_if_leveled(){
        if (current_exp >= exp_to_next_level){
            current_level++;
            LevelUp();
            exp_to_next_level *= LEVEL_SCALAR;
            return true;
        }
        return false;
    }
};

// Macro Constructor
#define PCCONSTRUCT : PlayerCharacterDelegate() {\
    HP->setMax(BASEHP);\
    HP->increaseCurrent(BASEHP);\
    increaseStats(BASESTR, BASEINT, BASEAGI);\
}

// Macro Level Up
#define LEVELUP void LevelUp() override {\
    HP->setMax((well_type)(BASEHP/2.f + HP->getMax()));\
    HP->increaseCurrent((well_type)(BASEHP/2.f + HP->getMax()));\
    increaseStats((stat_type)((BASESTR+1u)/2.f), (stat_type)((BASEINT+1u)/2.f), (stat_type)((BASEAGI+1u)/2.f));\
}

// Macro Player class
#define CHARACTERCLASS(classname, basehp, basestr, baseint, baseagi)\
class classname : public PlayerCharacterDelegate {\
public:\
    static const well_type BASEHP = (well_type)basehp;\
    static const stat_type BASESTR = (stat_type)basestr;\
    static const stat_type BASEINT = (stat_type)baseint;\
    static const stat_type BASEAGI = (stat_type)baseagi;\
    std::string getClassName() override { return std::string(#classname); }\
    classname() PCCONSTRUCT \
private:\
    LEVELUP\
};
// ----------------------Player Classes---------------------------------------
CHARACTERCLASS(Healer, 14, 3, 5, 1)
CHARACTERCLASS(Rogue, 14, 3, 3, 5)
CHARACTERCLASS(Wizard, 10, 1, 8, 1)
CHARACTERCLASS(Warrior, 18, 5, 2, 2)
// ----------------------Player Classes end-----------------------------------

class PlayerCharacter {
private:
    PlayerCharacterDelegate * pc_class;
public:
    PlayerCharacter() = delete;
    PlayerCharacter(PlayerCharacterDelegate * pc) : pc_class(pc) {}
    ~PlayerCharacter() {delete pc_class; pc_class = nullptr;}

    std::string getClassName()          { return pc_class->getClassName(); }
    level_type getLevel()               { return pc_class->getLevel(); }
    experience_type getCurrentEXP()     { return pc_class->getCurrentEXP(); }
    experience_type getEXPToNextLevel() { return pc_class->getEXPToNextLevel(); }
    well_type getCurrentHP()            { return pc_class->HP->getCurrent(); }
    well_type getMaxHP()                { return pc_class->HP->getMax(); }
    stat_type getStrength()             { return pc_class->getStrength(); }
    stat_type getIntellect()            { return pc_class->getIntellect(); }
    stat_type getAgility()              { return pc_class->getAgility(); }
    stat_type getArmor()                { return pc_class->getArmor(); }
    stat_type getElementResistance()    { return pc_class->getElementRes(); }

    void gainEXP(experience_type amt) { pc_class->gainEXP(amt); }
    void takeDamage(well_type amt) { pc_class->HP->reduceCurrent(amt); }
    void heal(well_type amt) { pc_class->HP->increaseCurrent(amt); }
};

#endif // PlayerCharacterDelegate_H