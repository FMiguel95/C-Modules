/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:16:50 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/18 23:46:06 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << ">> Create ClapTrap" << std::endl;
	ClapTrap ct("Ze");

	std::cout << std::endl;

	std::cout << ">> Create ScavTrap" << std::endl;
	ScavTrap st("Coiso");

	std::cout << std::endl;

	std::cout << ">> Create FragTrap" << std::endl;
	FragTrap ft("Fernando");

	std::cout << std::endl;

	std::cout << ">> show basic actions" << std::endl;
	ct.attack("Esteves");
	st.attack("Esteves");
	ft.attack("Esteves");
	
	std::cout << std::endl;

	std::cout << ">> special actions" << std::endl;
	st.guardGate();
	ft.highFivesGuys();

	std::cout << std::endl;

	return 0;
}