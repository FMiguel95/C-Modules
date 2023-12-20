/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:49:07 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 20:00:58 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Generic animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal& AAnimal::operator =(const AAnimal& src)
{
	std::cout << "Animal assignment operator overload called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

// void AAnimal::makeSound() const
// {
// 	std::cout << "* generic animal noises *" << std::endl;
// }

std::string AAnimal::getType() const
{
	return type;
}
