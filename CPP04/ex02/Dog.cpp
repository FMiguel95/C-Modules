/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:59:36 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 21:40:37 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(), brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& src) : AAnimal(src), brain(new Brain())
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog& Dog::operator =(const Dog& src)
{
	std::cout << "Dog assignment operator overload called" << std::endl;
	if (this != &src)
	{
		type = src.type;
		*brain = *(src.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::learn(std::string idea)
{
	brain->addIdea(idea);
}

void Dog::think() const
{
	brain->printIdeas();
}
