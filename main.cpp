#include <iostream>
#include "PlayerCharacter.h"

int main(){
    //.................test for player composition
    PlayerCharacter p1(new Wizard());

    for (int i = 0; i < 2; i++){
        std::cout 
            << p1.getClassName()
            << " Level (" << static_cast<int>(p1.getLevel()) << ")\n"
            << "-EXP: " << static_cast<int>(p1.getCurrentEXP()) << '/' 
                << static_cast<int>(p1.getEXPToNextLevel()) << '\n'
            << "-HP: " << p1.getCurrentHP() << '/' << p1.getMaxHP() << '\n'
            << "-Strength: " << static_cast<int>(p1.getStrength()) << '\n'
            << "-Intellect: " << static_cast<int>(p1.getIntellect()) << '\n';
        if(i < 1)
            p1.gainEXP(100u);
    }
    

    return 0;
}