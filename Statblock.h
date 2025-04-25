#include "typedef.h"
#include <iostream>


#ifndef STATBLOCK_H
#define STATBLOCK_H

class StatBlock {
public:
    StatBlock() {
        Strength = (stat_type)1u;
        Intellect = (stat_type)1u;
    }
    // explicit will only take uint8 types
    explicit StatBlock(stat_type s, stat_type i){
        Strength = s;
        Intellect = i;
        std::cout << "StatBlock created with Strength: " << Strength << ", Intellect: " << Intellect << "\n";
    }

    // Getters and Setters
    stat_type getStrength() {
        return Strength;
    }

    stat_type getIntellect() {
        return Intellect;
    }

private:
    stat_type Strength;
    stat_type Intellect;
};

#endif // STATBLOCK_H
