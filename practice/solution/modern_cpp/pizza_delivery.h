#ifndef PIZZA_DELIVERY_H
#define PIZZA_DELIVERY_H

#include <string> 

struct pizza
{
    int index;
    int numIngredients; 
    std::vector<std::string> ingredients; 
}; 

using pizza_arr = std::vector<pizza>; 

class PizzaDelivery
{
public:
    // constructor 
    // default 
    PizzaDelivery() = default;
    // default destructor 
    ~PizzaDelivery() = default; 
};

#endif //PIZZA_DELIVERY_H 
