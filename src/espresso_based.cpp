#include "espresso_based.h" 

EspressoBased::EspressoBased()
    :name{""}
    ,ingredients{}
{
};


EspressoBased::EspressoBased(const EspressoBased& esp)
    :ingredients{esp.ingredients}
    ,name{esp.name}
{
};


void EspressoBased::operator=(const EspressoBased& esp)
{
    if(this == &esp)
    {
        return;
    }
    ingredients = esp.ingredients;
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

