/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:52:42 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/26 21:32:29 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("unkown") {}

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& src) : _type(src._type) {}

AMateria& AMateria::operator =(const AMateria& src)
{
	if (this != &src)
	{
		
	}
	return *this;
}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* casts generic " << _type << " spell on " << target.getName() << " *" << std::endl;
}
		