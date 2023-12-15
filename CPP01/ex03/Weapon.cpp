/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:07:13 by fernacar          #+#    #+#             */
/*   Updated: 2023/10/23 00:10:46 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon( std::string type ) : type(type) {}

Weapon::~Weapon( void ) {}

std::string Weapon::getType() const
{
	return (type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
