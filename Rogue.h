#include "HP.h"
#include "Statblock.h"

// inherits from hp
class Rogue : public HP, public StatBlock {

public: 
    // make it static so it is only created once and not
    // everytime a warrior is made
    static const hp_type HPGROWTH = (hp_type) 13u;
    static const stat_type BASESTR = (stat_type) 3u;
    static const stat_type BASEINT = (stat_type) 2u;
    Rogue() : HP(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT) {}
private:
};