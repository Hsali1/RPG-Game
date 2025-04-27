#include "typedef.h"

#ifndef LevelSystem_H
#define LevelSystem_H

class LevelSystem {
public:
    static const experience_type LEVEL_2_AT = 100u;
    static const experience_type LEVEL_SCALAR = 2u; // multiplier for exp requirements

    LevelSystem(){
        current_level = 1u;
        current_exp = 0u;
        exp_to_next_level = LEVEL_2_AT;
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

#endif // LevelSystem_H