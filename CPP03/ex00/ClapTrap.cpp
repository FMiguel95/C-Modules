/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:15:13 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/11 22:19:06 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Assignment operator overide called" << std::endl;
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
		std::cout << "ClapTrap " << _name << " has no hit points left!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " was already dead." << std::endl;
	else if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " died!" << std::endl;
	}
	else
	{
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " has no hit points left!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
	else if (_hitPoints == 10)
		std::cout << "ClapTrap " << _name << " already has full hit points!" << std::endl;
	else
	{
		_energyPoints--;
		int newHP = _hitPoints + amount;
		if (newHP > 10)
			newHP = 10;
		int recovered = newHP - _hitPoints;
		_hitPoints = newHP;
		std::cout << "ClapTrap " << _name << " recovered " << recovered << " hit points! Total hit points: " << _hitPoints << std::endl;
	}
}
