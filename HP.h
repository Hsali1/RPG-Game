#include "typedef.h"

#ifndef HP_H
#define HP_H

class HP {
public:
    // returns true if set successfully
    bool setMaxHp(hp_type new_max_hp){
        if (new_max_hp < 1){
            return false;
        }

        maxHp = new_max_hp;

        if (currentHp > maxHp){
            currentHp = maxHp;
        }
        
        return true;
    }

    // getters
    hp_type getMaxHp(){
        return maxHp;
    }

    hp_type getCurrentHp(){
        return currentHp;
    }

    void takeDamage(hp_type damage){
        if (damage > currentHp){
            currentHp = 0;
        }else{
            currentHp -= damage;
        }
    }

    void heal(hp_type amount){
        if (amount + currentHp > maxHp){
            currentHp = maxHp;
        }else{
            currentHp += amount;
        }
    }

    // Constructor
    HP(){currentHp = 1; maxHp = 1;}
    HP(hp_type cHP, hp_type mHP){
        currentHp = cHP;
        maxHp = mHP;
        if (currentHp > maxHp){
            currentHp = maxHp;
        }
    }

private:
    hp_type currentHp;
    hp_type maxHp;
};

#endif // HP_H
