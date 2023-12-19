/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:16:50 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/19 01:10:21 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << ">> Create DiamondTrap" << std::endl;
	DiamondTrap dt("Diogo");

	std::cout << std::endl;

	std::cout << ">> show basic actions" << std::endl;
	dt.attack("Esteves");
	dt.takeDamage(85);
	dt.beRepaired(40);
	
	std::cout << std::endl;

	std::cout << ">> special actions" << std::endl;
	dt.guardGate();
	dt.highFivesGuys();
	dt.whoAmI();

	std::cout << std::endl;

	return 0;
}