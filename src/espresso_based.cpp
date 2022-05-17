#include "espresso_based.h" 

EspressoBased::EspressoBased()
    :name{""}
    ,ingredients{}
{
};


EspressoBased::EspressoBased(const EspressoBased& esp)
    :name{esp.name}
{
    for (Ingredient* component : esp.ingredients)
    {
        if(component->get_name() == "Cinnamon")
        {
            ingredients.push_back(new Cinnamon{component->get_units()});
        }
        else if(component->get_name() == "Chocolate")
        {
            ingredients.push_back(new Chocolate{component->get_units()});
        }
        else if(component->get_name() == "Sugar")
        {
            ingredients.push_back(new Sugar{component->get_units()});
        }
        else if(component->get_name() == "Cookie")
        {
            ingredients.push_back(new Cookie{component->get_units()});
        }
        else if(component->get_name() == "Espresso")
        {
            ingredients.push_back(new Espresso{component->get_units()});
        }
        else if(component->get_name() == "Milk")
        {
            ingredients.push_back(new Milk{component->get_units()});
        }
        else if(component->get_name() == "MilkFoam")
        {
            ingredients.push_back(new MilkFoam{component->get_units()});
        }
        else if(component->get_name() == "Water")
        {
            ingredients.push_back(new Water{component->get_units()});
        }

    }
};


void EspressoBased::operator=(const EspressoBased& esp)
{
    if(this == &esp)
    {
        return;
    }
    
    ingredients.clear();

    for (Ingredient* component : esp.ingredients)
    {
        if(component->get_name() == "Cinnamon")
        {
            ingredients.push_back(new Cinnamon{component->get_units()});
        }
        else if(component->get_name() == "Chocolate")
        {
            ingredients.push_back(new Chocolate{component->get_units()});
        }
        else if(component->get_name() == "Sugar")
        {
            ingredients.push_back(new Sugar{component->get_units()});
        }
        else if(component->get_name() == "Cookie")
        {
            ingredients.push_back(new Cookie{component->get_units()});
        }
        else if(component->get_name() == "Espresso")
        {
            ingredients.push_back(new Espresso{component->get_units()});
        }
        else if(component->get_name() == "Milk")
        {
            ingredients.push_back(new Milk{component->get_units()});
        }
        else if(component->get_name() == "MilkFoam")
        {
            ingredients.push_back(new MilkFoam{component->get_units()});
        }
        else if(component->get_name() == "Water")
        {
            ingredients.push_back(new Water{component->get_units()});
        }

    }
    name = esp.name;
};


EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
        delete i;
    ingredients.clear();
}


// EspressoBased::brew()
// {

// }


 std::vector<Ingredient*>& EspressoBased::get_ingredients()
 {
     return ingredients;
 }

