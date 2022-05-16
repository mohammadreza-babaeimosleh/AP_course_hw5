#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H
#include "ingredient.h"
#include <iostream>

#define DEFCLASS(subclass_name, ppu)\
class subclass_name : protected Ingredient\
{\
public:\
    subclass_name(size_t units) : Ingredient{ppu, units}\
    {\
        this->name = "subclass_name";\
        std::cout << "hello" << std::endl;\
    };\
    virtual std::string get_name() {return this->name;}\
};                              

DEFCLASS(Cinnamon, 5);

#endif // SUB_INGREDIENTS_H