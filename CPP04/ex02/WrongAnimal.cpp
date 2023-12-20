/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:41:39 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 17:53:54 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Generic wrong animal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator =(const WrongAnimal& src)
{
	std::cout << "WrongAnimal assignment operator overload called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "* generic wrong animal noises *" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}
