/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:43:43 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/18 23:40:53 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "- It's a ScavTrap!" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap attack!" << std::endl;
	if (_hitPoints == 0)
		std::cout << _name << " is too dead to attack." << std::endl;
	else if (_energyPoints == 0)
		std::cout << _name << " tried to attack but has no energy points left!" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (_hitPoints == 0)
		std::cout << _name << " is too dead to guard." << std::endl;
	else if (_energyPoints == 0)
		std::cout << _name << " tried guarding but has no energy points left!" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
	}
}
