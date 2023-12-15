/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:16:50 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/11 22:23:49 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << ">> Create ClapTrap" << std::endl;
	ClapTrap ze("Ze");

	std::cout << std::endl;

	std::cout << ">> show basic actions" << std::endl;
	ze.attack("Esteves");
	ze.beRepaired(5);
	ze.takeDamage(8);
	ze.beRepaired(6);
	ze.beRepaired(4);
	
	std::cout << std::endl;

	std::cout << ">> spend all energy points" << std::endl;
	ze.attack("Esteves");
	ze.attack("Esteves");
	ze.attack("Esteves");
	ze.attack("Esteves");
	ze.attack("Esteves");
	ze.attack("Esteves");
	ze.attack("Esteves");

	std::cout << std::endl;
	
	std::cout << ">> no energy left to do actions" << std::endl;
	ze.attack("Esteves");
	ze.takeDamage(5);
	ze.beRepaired(10);

	std::cout << std::endl;

	std::cout << ">> kill it" << std::endl;
	ze.takeDamage(9999);

	std::cout << std::endl;

	std::cout << ">> no hit points left to do actions" << std::endl;
	ze.attack("Esteves");
	ze.beRepaired(10);
	ze.takeDamage(5);

	std::cout << std::endl;

	return 0;
}