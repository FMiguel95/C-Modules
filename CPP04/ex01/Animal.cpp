/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:49:07 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/19 23:43:44 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Generic animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator =(const Animal& src)
{
	std::cout << "Animal assignment operator overload called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "* generic animal noises *" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
