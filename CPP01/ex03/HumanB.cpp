/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:07:50 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/29 20:33:42 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name ) : name(name)
{
	weapon = NULL;
}

HumanB::~HumanB( void ) {}

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " doesn't have a weapon" << std::endl;
}

void HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}
