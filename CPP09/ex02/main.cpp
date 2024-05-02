/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:11:54 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/30 19:06:26 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>



int main(int ac, char** av)
{
	bool error = false;
	for (int i = 1; i < ac; i++)
	{
		std::string arg(av[i]);
		for (size_t j = 0; j < arg.length(); j++)
		{
			// and empty strings...?
			if (!std::isdigit(av[i][j]) || arg.length() == 0)
			{
				std::cerr << "Argument '" << arg << "' is not a positive number." << std::endl;
				error = true;
			}
		}
	}
	if (error)
		return 1;

	PmergeMe fj(ac, av);
	std::vector<unsigned int> vec = fj.sortVector();

	for (size_t i = 1; i < vec.size(); i++)
	{
		if (vec[i] < vec[i-1])
		{
			std::cout << "NOT SORTED >:(" << std::endl;
			return 1;
		}
	}
	std::cout << "sorted" << std::endl;
	
	return 0;
}
