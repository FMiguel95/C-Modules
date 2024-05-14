/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:11:54 by fernacar          #+#    #+#             */
/*   Updated: 2024/05/08 20:23:13 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>



int main(int ac, char** av)
{
	if (ac == 1)
	{
		std::cout << "Usage: ./PmergeMe <n1> <n2> ..." << std::endl;
		return 1;
	}
	bool quit = false;
	// check for non digits, just 0, and empty args
	for (int i = 1; i < ac; i++)
	{
		bool error = false;
		std::string arg(av[i]);
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!std::isdigit(av[i][j]))
			{
				error = true;
				break;
			}
		}
		if (arg.length() == 0 || arg == "0")
			error = true;
		if (error)
		{
			std::cout << "Argument '" << arg << "' is not a positive number." << std::endl;
			quit = true;
		}
	}
	if (quit)
		return 1;

	// check for duplicates
	for (int i = 1; i < ac; i++)
	{
		std::string arg(av[i]);
		for (int j = i + 1; j < ac; j++)
		{
			if (arg == av[j])
			{
				std::cout << arg << ": duplicate argument." << std::endl;
				quit = true;
				break;
			}
		}
	}
	if (quit)
		return 1;

	PmergeMe fj(ac, av);
	
	return 0;
}
