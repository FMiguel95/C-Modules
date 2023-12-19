/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:15:13 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/18 23:37:56 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap assignment operator overide called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
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

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _name << " took " << amount << " points of damage!";
	if (_hitPoints == 0)
		std::cout << "\n- " << _name << " was already dead." << std::endl;
	else if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "\n- " << _name << " died!" << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << " Total hit points: " << _hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << _name << " is too dead to repair itself." << std::endl;
	else if (_energyPoints == 0)
		std::cout << _name << " tried repairing but has no energy points left!" << std::endl;
	else
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << _name << " recovered " << amount << " hit points! Total hit points: " << _hitPoints << std::endl;
	}
}
