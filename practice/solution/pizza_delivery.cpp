#include "pizza_delivery.h"

#include <iostream> 

std::ostream& operator<<(std::ostream& os, pizza_vec pv) noexcept
{
    for (const auto& pizza : pv)
    {
	os << "pizza index: " << pizza.index << " number of ingredients: " << pizza.numIngredients << std::endl; 
	os << "ingredients:" << std::endl; 
	for (const auto& ing : pizza.ingredients)
	{
	    os << ing << std::endl;  
	}
    }
    return os; 
}

std::unordered_map<int, std::vector<int>> PizzaDelivery::solve() noexcept
{
    std::unordered_map<int, std::vector<int>> results; 

    // while loop as long as team not zero and pizza not zero  
    // select largest team whose size is smaller than number 
    // of remaining pizza 
    // select one pizza, and then select from remaining pizza which has min. overlap 
    // until all people in team gets one pizza  

    return results; 
}	

int PizzaDelivery::total_diff_ingred_for_two_piz(const pizza& p1, const pizza& p2) noexcept
{
    std::vector<std::string> v(p1.numIngredients + p2.numIngredients);
    std::vector<std::string>::iterator it, st; 
    
    st = v.begin(); 
    it = std::set_intersection(p1.ingredients.begin(), p1.ingredients.end(),
			p2.ingredients.begin(), p2.ingredients.end(),
			v.begin());

    int numDiffIngred = p1.numIngredients + p2.numIngredients - std::distance(it, st);

    return numDiffIngred; 
}


