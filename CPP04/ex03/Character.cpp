/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:21:32 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/27 00:40:55 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default")
{
	for (size_t i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Character " << _name << " created" << std::endl;
}

Character::Character(const std::string& name) : _name(name)
{
	for (size_t i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Character " << _name << " created" << std::endl;
}

Character::Character(const Character& src)
{
	for (size_t i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	*this = src;
	std::cout << "Character " << _name << " copied" << std::endl;
}

Character& Character::operator =(const Character& src)
{
	if (this != &src)
	{
		_name = src._name;
		for (size_t i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}


const std::string& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Invalid materia." << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (m == _inventory[i])
		{
			std::cout << _name << " already has this materia equipped." << std::endl;
			return;
		}
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _name << " equipped materia of type " << m->getType() << " on slot " << i << "." << std::endl;
			return ;
		}
	}
	std::cout << _name << "'s inventory is full. Materia of type " << m->getType() << " can't be equipped." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << "Invalid slot." << std::endl;
	else if (!_inventory[idx])
		std::cout << _name << "'s slot " << idx << " is already empty." << std::endl;
	else
	{
		AMateria* unequipped = _inventory[idx];
		_inventory[idx] = NULL;
		std::cout << "Materia of type " << unequipped->getType() << " unequipped from " << _name << "'s slot " << idx << "." << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		std::cout << "Invalid slot." << std::endl;
	else if (!_inventory[idx])
		std::cout << _name << "'s slot " << idx << " is empty." << std::endl;
	else
	{
		std::cout << _name << " uses a materia of type " << _inventory[idx]->getType() << ": ";
		_inventory[idx]->use(target);
	}
}
