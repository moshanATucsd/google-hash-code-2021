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
