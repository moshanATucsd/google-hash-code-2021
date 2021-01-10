#ifndef UTILS_H
#define UTILS_H 

#include <exception>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "pizza_delivery.h" 

PizzaDelivery parse_input(const std::string& filename)
{
    std::ifstream ifs(filename); 

    if (!ifs.is_open()) 
    {
    	throw std::ios_base::failure("Cannot open input file");
    }

    int numPizza, numTeamTwo, numTeamThree, numTeamFour;
    ifs >> numPiazza >> numTeamTwo >> numTeamThree >> numTeamFour;
    // deal with newline 
    ifs.get();

    pizza_arr pizzas; 
    for (int i = 0; i < numPizza; ++i)
    {
	// read one pizza 
        pizza piz;  
	piz.index = i; 
        int numIngredients = ifs.get();	

	for (int j = 0; j < numIngredients; ++j) 
	{
	    char ingredient = ifs.get();
            piz.ingredients.push_back(ingredient);
	}
	
	// use move instead of copy 
	pizzas.push_back(std::move(piz));

	// deal with newline 
	ifs.get(); 
    }
	
    return PizzaDelivery(); 
}

void save_results(const std::string& filename)
{
    std::ofstream ofs(filename); 

    if (!ofs.is_open()) 
    {
        throw std::ios_base::failure("Cannot open the output file");
    }

}

#endif // UTILS_H 
