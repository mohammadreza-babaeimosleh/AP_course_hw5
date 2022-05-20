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


void EspressoBased::brew()
{
    using namespace ftxui;
    using namespace std::chrono_literals;
    
    double sum_unit{};
    for (auto components : ingredients)
    {
        sum_unit += components->get_units();
    }

    float step{ 1 / sum_unit };
    std::cout << step << std::endl;
    
    std::string reset_position{};
    std::string reset_position2{};
    float ratio{};
    std::vector<std::string> sub_component;
    sub_component.push_back("");
    sub_component.push_back("");
    sub_component.push_back("");

    Decorator color1{color(Color::Blue)};
    Decorator color2{color(Color::Yellow)};
    Decorator color3{color(Color::Green)};

    std::vector< Decorator> color_coll;
    std::vector< Decorator> color_coll_itr;

    color_coll_itr.push_back(color1);
    color_coll_itr.push_back(color2);
    color_coll_itr.push_back(color3);

    color_coll.push_back(color(Color::Black));
    color_coll.push_back(color(Color::Black));
    color_coll.push_back(color(Color::Black));
    size_t counter{};
    for (auto components : ingredients)
    {

        sub_component[2] = sub_component[1];
        sub_component[1] = sub_component[0];
        sub_component[0] = components->get_name();

        color_coll[2] = color_coll[1];
        color_coll[1] = color_coll[0];
        color_coll[0] = color_coll_itr[counter];  
        
        float partial_step{step / (components->get_units() * 10)};
        for (int i{} ; i < components->get_units() * 10 ; i++)
        {

                    Element document = border (hbox({
                text("brewing: ") | color(Color::Blue)
                ,gaugeRight( ratio ) | color(Color::Magenta)
                ,border(vbox({
                     text(sub_component[0]) | border | color_coll[0]
                    ,text(sub_component[1]) | border | color_coll[1]
                    ,text(sub_component[2]) | border | color_coll[2]

                }))
                ,text("                     ")
            }))| color(Color::Red);
                        

            ratio += partial_step * components->get_units();
            auto screen = Screen::Create(Dimension::Full(), Dimension::Fixed(13));
            Render(screen, document);
            std::cout << reset_position;
            screen.Print();
            reset_position = screen.ResetPosition();

            std::this_thread::sleep_for(0.5s);
        }
        counter++;
    }
            Element document = border(hbox({
            text("brewing: ") | color(Color::Blue)
        ,gaugeRight( ratio ) | color(Color::Magenta)
        ,border(vbox({
             text(sub_component[0]) | border | color_coll[0]
            ,text(sub_component[1]) | border | color_coll[1]
            ,text(sub_component[2]) | border | color_coll[2]
        }))
        ,text("                     ")
    })) | color(Color::Red);
    auto screen = Screen::Create(Dimension::Full(), Dimension::Fixed(13));
    Render(screen, document);
    std::cout << reset_position;
    screen.Print();
    reset_position = screen.ResetPosition();
    std::this_thread::sleep_for(1s);
    


    std::cout << "" << std::endl;
}


 std::vector<Ingredient*>& EspressoBased::get_ingredients()
 {
     return ingredients;
 }

