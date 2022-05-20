#include "mocha.h"



Mocha::Mocha() 
    : EspressoBased{}
    , side_items{}
{
    Milk* milk{new Milk{2}};
    Espresso* espresso{new Espresso{2}};
    MilkFoam* milkfoam{new MilkFoam{1}};
    Chocolate* chocolate{new Chocolate{1}};
    ingredients.push_back(milk);
    ingredients.push_back(espresso);
    ingredients.push_back(milkfoam);
    ingredients.push_back(chocolate);
    name = "Mocha";
};


Mocha::Mocha(const Mocha& cap)
    :EspressoBased{cap}
{
    for (Ingredient* component : cap.side_items)
    {
        if(component->get_name() == "Cinnamon")
        {
            side_items.push_back(new Cinnamon{component->get_units()});
        }
        else if(component->get_name() == "Chocolate")
        {
            side_items.push_back(new Chocolate{component->get_units()});
        }
        else if(component->get_name() == "Sugar")
        {
            side_items.push_back(new Sugar{component->get_units()});
        }
        else if(component->get_name() == "Cookie")
        {
            side_items.push_back(new Cookie{component->get_units()});
        }
        else if(component->get_name() == "Espresso")
        {
            side_items.push_back(new Espresso{component->get_units()});
        }
        else if(component->get_name() == "Milk")
        {
            side_items.push_back(new Milk{component->get_units()});
        }
        else if(component->get_name() == "MilkFoam")
        {
            side_items.push_back(new MilkFoam{component->get_units()});
        }
        else if(component->get_name() == "Water")
        {
            side_items.push_back(new Water{component->get_units()});
        }

    }
};


void Mocha::operator=(const Mocha& cap)
{
    if(this == &cap)
    {
        return;
    }

    side_items.clear();

    for (Ingredient* component : cap.side_items)
    {
        if(component->get_name() == "Cinnamon")
        {
            side_items.push_back(new Cinnamon{component->get_units()});
        }
        else if(component->get_name() == "Chocolate")
        {
            side_items.push_back(new Chocolate{component->get_units()});
        }
        else if(component->get_name() == "Sugar")
        {
            side_items.push_back(new Sugar{component->get_units()});
        }
        else if(component->get_name() == "Cookie")
        {
            side_items.push_back(new Cookie{component->get_units()});
        }
        else if(component->get_name() == "Espresso")
        {
            side_items.push_back(new Espresso{component->get_units()});
        }
        else if(component->get_name() == "Milk")
        {
            side_items.push_back(new Milk{component->get_units()});
        }
        else if(component->get_name() == "MilkFoam")
        {
            side_items.push_back(new MilkFoam{component->get_units()});
        }
        else if(component->get_name() == "Water")
        {
            side_items.push_back(new Water{component->get_units()});
        }

    }
};


Mocha::~Mocha()
{
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
};


std::string Mocha::get_name()
{
    return name;
}


double Mocha::price()
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

void Mocha::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items()
{
    return side_items;
}

