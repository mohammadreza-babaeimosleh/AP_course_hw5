#include "cappuccino.h"


Cappuccino::Cappuccino() 
    : EspressoBased{}
    , side_items{}
{
    Milk* milk{new Milk{2}};
    Espresso* espresso{new Espresso{2}};
    MilkFoam* milkfoam{new MilkFoam{1}};
    ingredients.push_back(milk);
    ingredients.push_back(espresso);
    ingredients.push_back(milkfoam);
    name = "Cappuccino";
};


Cappuccino::Cappuccino(const Cappuccino& cap)
    :side_items{cap.side_items}
{
    ingredients = cap.ingredients;
};


void Cappuccino::operator=(const Cappuccino& cap)
{
    if(this == &cap)
    {
        return;
    }
    side_items = cap.side_items;
    ingredients = cap.ingredients;
};


Cappuccino::~Cappuccino()
{
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
};


std::string Cappuccino::get_name()
{
    return name;
}


double Cappuccino::price()
{
    double value{};
    for (Ingredient* component : ingredients)
    {
        value += (*component).price();
    }

    for (Ingredient* component : side_items)
    {
        value += (*component).price();
    }

    return value;
}

void Cappuccino::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items()
{
    return side_items;
}

