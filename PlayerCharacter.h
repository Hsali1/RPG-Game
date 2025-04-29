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

    PlayerCharacterDelegate() : StatBlock(0u, 0u){
        current_level = 1u;
        current_exp = 0u;
        exp_to_next_level = LEVEL_2_AT;
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
    increaseStats(BASESTR, BASEINT);\
}

// Macro Level Up
#define LEVELUP void LevelUp() override {\
    HP->setMax((well_type)(BASEHP/2.f + HP->getMax()));\
    HP->increaseCurrent((well_type)(BASEHP/2.f + HP->getMax()));\
    increaseStats((stat_type)((BASESTR+1u)/2.f), (stat_type)((BASEINT+1u)/2.f));\
}

class Healer : public PlayerCharacterDelegate {
public: 
  
    static const well_type BASEHP = (well_type)14u;
    static const stat_type BASESTR = (stat_type) 2u;
    static const stat_type BASEINT = (stat_type) 3u;

    Healer() PCCONSTRUCT

    std::string getClassName() override {
        return std::string("Healer");
    }
private:
    LEVELUP
};

class Rogue : public PlayerCharacterDelegate {
public: 

    static const well_type BASEHP = (well_type)12u;
    static const stat_type BASESTR = (stat_type) 3u;
    static const stat_type BASEINT = (stat_type) 2u;

    Rogue() PCCONSTRUCT

    std::string getClassName() override {
        return std::string("Rogue");
    }
private:
    LEVELUP
};

class Warrior : public PlayerCharacterDelegate {
public: 

    static const well_type BASEHP = (well_type)18u;
    static const stat_type BASESTR = (stat_type) 4u;
    static const stat_type BASEINT = (stat_type) 1u;

    Warrior() PCCONSTRUCT

    std::string getClassName() override {
        return std::string("Warrior");
    }
private:
    LEVELUP 
};

class Wizard : public PlayerCharacterDelegate {
public: 

    static const well_type BASEHP = (well_type) 10u;
    static const stat_type BASESTR = (stat_type) 1u;
    static const stat_type BASEINT = (stat_type) 4u;

    Wizard() PCCONSTRUCT

    std::string getClassName() override {
        return std::string("Wizard");
    }
private:
    LEVELUP
};

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

    void gainEXP(experience_type amt) { pc_class->gainEXP(amt); }
    void takeDamage(well_type amt) { pc_class->HP->reduceCurrent(amt); }
    void heal(well_type amt) { pc_class->HP->increaseCurrent(amt); }
};

#endif // PlayerCharacterDelegate_H