#ifndef PIZZA_DELIVERY_H
#define PIZZA_DELIVERY_H

#include <string> 
#include <unordered_map>

struct pizza
{
    int index;
    int numIngredients; 
    std::vector<std::string> ingredients; 
}; 

using pizza_vec = std::vector<pizza>; 

class PizzaDelivery
{
public:
    // constructor 
    // default constructor 
    PizzaDelivery() = default;
    // default destructor 
    ~PizzaDelivery() = default; 
    
    // constructor we use 
    // use rvalue to avoid copying 
    PizzaDelivery(pizza_vec&& pizzas, std::vector<int> teamNums) noexcept 
	: m_pizzas{std::move(pizzas)}, m_teamNums{teamNums}

    // function to solve the problem 
    std::unordered_map<int, std::vector<int>> solve() noexcept; 

private:

    int total_diff_ingred_for_two_piz(const pizza& p1, const pizza& p2) noexcept;

    pizza_vec m_pizzas; 
    std::vector<int> m_teamNums; 
};

#endif //PIZZA_DELIVERY_H 
