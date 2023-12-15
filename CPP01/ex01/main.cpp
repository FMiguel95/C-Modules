/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:15:18 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/29 19:10:45 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	std::cout << ">>> 1 zombie horde" << std::endl;
	std::cout << "> Zombie *horde = zombieHorde(1, \"Ze\");" << std::endl;
	Zombie *horde = zombieHorde(1, "Ze");
	std::cout << "> horde[0].announce();" << std::endl;
	horde[0].announce();
	// std::cout << "> horde[1].announce();" << std::endl;
	// horde[1].announce();
	std::cout << "> delete[] horde;" << std::endl;
	delete[] horde;

	std::cout << std::endl;

	std::cout << ">>> 5 zombie horde" << std::endl;
	std::cout << "> horde = zombieHorde(5, \"Fernando\");" << std::endl;
	horde = zombieHorde(5, "Fernando");
	std::cout << "> announcements" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}
	std::cout << "> delete[] horde;" << std::endl;
	delete[] horde;

	std::cout << std::endl;

	std::cout << ">>> 0 zombie horde" << std::endl;
	std::cout << "> horde = zombieHorde(0, \"Miguel\");" << std::endl;
	horde = zombieHorde(0, "Miguel");
	// std::cout << "> horde[0].announce();" << std::endl;
	// horde[0].announce();
	std::cout << "> delete[] horde;" << std::endl;
	delete[] horde;

	return (0);
}