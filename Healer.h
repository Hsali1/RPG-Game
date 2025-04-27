#include "HP.h"
#include "Statblock.h"
#include "LevelSystem.h"

// inherits from hp
class Healer : public HP, public StatBlock, public LevelSystem {

public: 
    // make it static so it is only created once and not
    // everytime a healer is made
    static const hp_type HPGROWTH = (hp_type) 7u;
    static const stat_type STRGROWTH = (stat_type)1u;
    static const stat_type INTGROWTH = (stat_type)2u;

    static const hp_type BASEHP = (hp_type)14u;
    static const stat_type BASESTR = (stat_type) 2u;
    static const stat_type BASEINT = (stat_type) 3u;

    Healer() : HP(BASEHP, BASEHP), StatBlock(BASESTR, BASEINT) {}
private:
    void LevelUp() override {
        setMaxHp(HPGROWTH + getMaxHp());
        increaseStats(STRGROWTH, INTGROWTH);
    }
};