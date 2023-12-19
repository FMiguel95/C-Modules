/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:16:50 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/18 23:11:01 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << ">> Create ClapTrap and ScavTrap" << std::endl;
	ClapTrap ct("Ze");
	ScavTrap st("Coiso");

	std::cout << std::endl;

	std::cout << ">> show basic actions" << std::endl;
	ct.attack("Esteves");
	st.attack("Esteves");
	
	std::cout << std::endl;

	std::cout << ">> guard gate" << std::endl;
	st.guardGate();

	std::cout << std::endl;

	return 0;
}