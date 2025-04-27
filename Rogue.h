#include "HP.h"
#include "Statblock.h"
#include "LevelSystem.h"

// inherits from hp
class Rogue : public HP, public StatBlock, public LevelSystem {

public: 
    // make it static so it is only created once and not
    // everytime a rogue is made
    static const hp_type HPGROWTH = (hp_type) 6u;
    static const stat_type STRGROWTH = (stat_type)2u;
    static const stat_type INTGROWTH = (stat_type)1u;

    static const hp_type BASEHP = (hp_type) 12u;
    static const stat_type BASESTR = (stat_type) 3u;
    static const stat_type BASEINT = (stat_type) 2u;

    Rogue() : HP(BASEHP, BASEHP), StatBlock(BASESTR, BASEINT) {}
private:
void LevelUp() override {
    setMaxHp(HPGROWTH + getMaxHp());
    increaseStats(STRGROWTH, INTGROWTH);
}
};