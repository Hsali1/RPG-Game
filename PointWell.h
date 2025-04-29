#include "typedef.h"

#ifndef PointWell_H
#define PointWell_H

class PointWell {
public:
    // returns true if set successfully
    bool setMax(well_type new_max){
        if (new_max < 1){
            return false;
        }

        max = new_max;

        if (current > max){
            current = max;
        }
        
        return true;
    }

    // getters
    well_type getMax(){
        return max;
    }

    well_type getCurrent(){
        return current;
    }

    void reduceCurrent(well_type damage){
        if (damage > current){
            current = 0;
        }else{
            current -= damage;
        }
    }

    void increaseCurrent(well_type amount){
        if (amount + current > max){
            current = max;
        }else{
            current += amount;
        }
    }

    // Constructor
    PointWell(){current = 1; max = 1;}
    PointWell(well_type c, well_type m){
        current = c;
        max = m;
        if (current > max){
            current = max;
        }
    }

private:
    well_type current;
    well_type max;
};

#endif // PointWell_H
