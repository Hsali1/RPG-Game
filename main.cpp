#include <iostream>
#include "allClasses.h"

int main(){

    Warrior warr1;
    Wizard wiz1;
    Healer heal1;
    Rogue rog1;

    std::cout << "Warrior\n" 
        << "-MaxHP: " << warr1.getMaxHp() << "\n";
    std::cout << "-CurrentHp: " << warr1.getCurrentHp() << "\n";
    std::cout << "-Strength: " << static_cast<int>(warr1.getStrength()) << "\n";
    std::cout << "-Intellect: " << static_cast<int>(warr1.getIntellect()) << "\n";


    std::cout << "Wizard\n" 
        << "-MaxHP: " << wiz1.getMaxHp() << "\n";
    std::cout << "-CurrentHp: " << wiz1.getCurrentHp() << "\n";
    std::cout << "-Strength: " << static_cast<int>(wiz1.getStrength()) << "\n";
    std::cout << "-Intellect: " << static_cast<int>(wiz1.getIntellect()) << "\n";

    std::cout << "Healer\n"
        << "-MaxHP: " << heal1.getMaxHp() << "\n";
    std::cout << "-CurrentHp: " << heal1.getCurrentHp() << "\n";
    std::cout << "-Strength: " << static_cast<int>(heal1.getStrength()) << "\n";
    std::cout << "-Intellect: " << static_cast<int>(heal1.getIntellect()) << "\n";

    std::cout << "Rogue\n"
        << "-MaxHP: " << rog1.getMaxHp() << "\n";
    std::cout << "-CurrentHp: " << rog1.getCurrentHp() << "\n";
    std::cout << "-Strength: " << static_cast<int>(rog1.getStrength()) << "\n";
    std::cout << "-Intellect: " << static_cast<int>(rog1.getIntellect()) << "\n";

    return 0;
}