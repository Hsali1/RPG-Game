#include "HP.h"
#include "Statblock.h"

// inherits from hp
class Warrior : public HP, public StatBlock {

public: 
    // make it static so it is only created once and not
    // everytime a warrior is made
    static const hp_type HPGROWTH = (hp_type) 19u;
    static const stat_type BASESTR = (stat_type) 4u;
    static const stat_type BASEINT = (stat_type) 1u;
    Warrior() : HP(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT) {}
private:
};