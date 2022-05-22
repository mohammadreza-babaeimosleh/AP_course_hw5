#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H
#include<vector>
#include<string>
#include"sub_ingredients.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "ftxui/dom/node.hpp"      // for Render
#include "ftxui/screen/color.hpp"  // for ftxui
#include <iostream>
#include <thread>

class EspressoBased
{
public:
    virtual std::string get_name() = 0; //pure virtual
    virtual double price() = 0; //pure virtual

    void brew();
    std::vector<Ingredient*>& get_ingredients();

    virtual ~EspressoBased();

protected:
    EspressoBased();
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;

};

#endif // ESPRESSO_BASED_H