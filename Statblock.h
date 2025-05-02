#include "typedef.h"
#include <iostream>


#ifndef STATBLOCK_H
#define STATBLOCK_H

class StatBlock {
public:
    // explicit will only take uint8 types
    explicit StatBlock(
            stat_type s = (stat_type)1u,
            stat_type i = (stat_type)1u,
            stat_type a = (stat_type)1u,
            stat_type armor = (stat_type)0u,
            stat_type e_res = (stat_type)0u
                    ){
        Strength = s;
        Intellect = i;
        Agility = a;
        Armor = armor;
        ElementRes = e_res;
        // std::cout << "StatBlock created with Strength: " << Strength << ", Intellect: " << Intellect << "\n";
    }

    // Getters and Setters
    stat_type getStrength() {return Strength;}
    stat_type getIntellect() {return Intellect;}
    stat_type getAgility() {return Agility;}
    stat_type getArmor() {return Armor;}
    stat_type getElementRes() { return ElementRes;}

private:
    stat_type Strength;
    stat_type Intellect;
    stat_type Agility;
    stat_type Armor;
    stat_type ElementRes;

protected:
    void increaseStats(
        stat_type s = (stat_type)0u,
        stat_type i = (stat_type)0u,
        stat_type a = (stat_type)0u,
        stat_type armor = (stat_type)0u,
        stat_type e_res = (stat_type)0u
    ){
        Strength += s;
        Intellect += i;
        Agility += a;
        Armor += armor;
        ElementRes = e_res;
    }
};

#endif // STATBLOCK_H
