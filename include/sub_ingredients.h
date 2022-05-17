#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H
#include "ingredient.h"
#include <iostream>
#include <string> 

#define DEFCLASS(subclass_name, ppu)\
class subclass_name : public Ingredient\
{\
public:\
    subclass_name(size_t units) : Ingredient{ppu, units}\
    {\
        this->name = #subclass_name;\
    };\
    virtual std::string get_name() {return this->name;}\
};                              

 DEFCLASS(Cinnamon, 5);
 DEFCLASS(Chocolate, 5);
 DEFCLASS(Sugar, 1);
 DEFCLASS(Cookie, 10);
 DEFCLASS(Espresso, 15);
 DEFCLASS(Milk, 10);
 DEFCLASS(MilkFoam, 5);
 DEFCLASS(Water, 1);


#endif // SUB_INGREDIENTS_H