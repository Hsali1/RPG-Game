To run = g++ main.cpp -o rpp_game

# Demo_rpg

Warrior - HP Growth 20 : Highest damage reduction
Mage - HP Growth 10 : Magic damage
Healer - HP Growth 14 : Support Magic
Rogue - HP Growth 12 : Highest consistent mele/ranged damage

## designs

quick theoretical lists to get started

### leveling system

- gain tats based on class
- gain abilities based on level

### equipment

- shop system
- equipment
- consumables

### game loop

- battle system: turn based
- world levels
- different monsters

# Code

## PlayerCharacter.h

### PlayerCharacterDelegate : public StatBlock

PlayerCharacterDelegate is a pure virtual class \
will inherit from StatBlock \
Properties:
    - static const experience_type LEVEL_2_AT = 100u;
    - static const experience_type LEVEL_SCALAR = 2u;
    - level_type current_level;           // Used to track the current level
    - experience_type current_exp;        // Used to track current experience
    - experience_type exp_to_next_level;  // Used to track the exp req for next level
    - std::unique_ptr<PointWell> HP;      // Providing us access to the PointWell class
    - stat_type Strength;                 // From the Statblock class to manage Strength
    - stat_type Intellect;                // From the Statblock class to manage Strength
Functions:
    - PlayerCharacterDelegate() : StatBlock(0u, 0u)
        Initiates the StatBlock constructor with strength and intellect = 0
        Sets the initial values for:
            - current_level
            - current_exp
            - exp_to_next_level
        Makes HP points to an instance of the Pointwell class
    - void gainEXP(experience_type gained_exp)
        Adds gained_exp to the current_exp
        Checks to make sure if the character has leveled up
    - bool check_if_leveled()
        If character can not level up returns false
        if character can level up:
            Incremenets the level
            Calls the LevelUp virual function
            Sets the exp required for next level
    - Virtual Functions
        virtual void LevelUp() = 0;
        virtual std::string getClassName() = 0;
    - Getters
        level_type getLevel()
        experience_type getCurrentEXP()
        experience_type getEXPToNextLevel()
    // Inherited
        void increaseStats(stat_type s, stat_type i)
            adds s to current strength
            adds i to current intellect

### Player Classes

They inherit from PlayerCharacterDelegate\
properties:
    - static const well_type BASEHP       // unique characteristic of each player 
    - static const stat_type BASESTR      // unique characteristic of each player 
    - static const stat_type BASEINT      // unique characteristic of each player 
    Functions
        - Healer()
            Initiates the constructor for PlayerCharacterDelegate
            Sets the current and max HP
            Sets the stats based on the unique characteristic
        - std::string getClassName() override
            returns the name of the class
        - void LevelUp() override 
            Increases Max and Current health
            Increases stats

### PlayerCharacter

We will use this class to create players\
usage example:  PlayerCharacter p1(new Wizard());\
properties:\
    PlayerCharacterDelegate * pc_class; // will be used to access everything\
Functions:\
    PlayerCharacter(PlayerCharacterDelegate * pc) : pc_class(pc)\