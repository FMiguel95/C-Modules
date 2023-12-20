/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:04:44 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 21:40:45 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal(), brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& src) : AAnimal(src), brain(new Brain())
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator =(const Cat& src)
{
	std::cout << "Cat assignment operator overload called" << std::endl;
	if (this != &src)
	{
		type = src.type;
		*brain = *(src.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::learn(std::string idea)
{
	brain->addIdea(idea);
}

void Cat::think() const
{
	brain->printIdeas();
}
