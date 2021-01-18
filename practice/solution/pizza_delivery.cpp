#include "pizza_delivery.h"

#include <iostream> 
#include <numeric> 

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
    // break when number of pizza available is smaller than existing smaller team size

    // select largest team whose size is smaller than number 
    // of remaining pizza 
    // select one pizza, and then select from remaining pizza which has min. overlap 
    // until all people in team gets one pizza  

    while (m_pizzas.size() && std::accumulate(m_teamNums.begin(), m_teamNums.end(), decltype(m_teamNums)::value_type(0)))
    {

	// break 
	int smallest_team_size = 0; 	
	for (const auto& num : m_teamNums)
	{
	    if (num != 0) 
	    {
		smallest_team_size = num; 
		break; 
	    }
	}
	if (m_pizzas.size() < smallest_team_size)
	    break;  
        
	// select the largest team 	
	int largest_team_size = 0; 
	for (auto it = m_teamNums.rbegin(); it != m_teamNums.rend(); ++it)
	{
	    if (*it != 0)
	    {
		largest_team_size = *it; 
		*it--; 
		break; 
	    }
	}
	
	// check if we still have enough pizza 
	if (m_pizzas.size() < largest_team_size)
	    continue; 

	// write this team size in results 
 	results[largest_team_size] = std::vector<int> piz_list; 
	
	// pick the pizza that has most new ingredients 
	std::vector<std::string> current_ingred_list;	
	int temp_team_size = largest_team_size; 
 	while (temp_team_size != 0)
	{
	    int largest_new_ingred = 0; 
	    int chosen_piz_index; 	
	    for (const auto& piz : m_pizzas)
	    {
		int numNewIngred = diff_ingred_for_cur_piz(current_ingred_list, piz);
		if (largest_new_ingred < numNewIngred)
		{
		    larget_new_ingred = numNewIngred; 
		    chosen_piz_index = piz.index; 
		}
	    }
	    
	    // add chosen pizza to results 
	    results[largest_team_size].push_back(chosen_piz_index];

	    // remove chosen pizza 
	    pizza_vec::iterator it = remove_if(m_pizzas.begin(), m_pizzas.end(), [](pizza piz){return piz.index == chosen_piz_index;}); 
	    m_pizzas.erase(it); 
		
	    temp_team_size--; 
	}	
	    
    }

    return results; 
}	

int PizzaDelivery::diff_ingred_for_cur_piz(const std::vector<std::string>& ing_list, const pizza& p) noexcept
{
    std::vector<std::string>::iterator it, st; 
    
    st = v.begin(); 
    it = std::set_intersection(ing_list.begin(), ing_list.end(),
			p.ingredients.begin(), p.ingredients.end(),
			v.begin());

    int numDiffIngred = p.numIngredients - std::distance(it, st);

    return numDiffIngred; 
}


