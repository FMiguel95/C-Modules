/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:32:25 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 19:19:15 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain& Brain::operator =(const Brain& src)
{
	std::cout << "Brain assignment operator overload called" << std::endl;
	if (this != &src)
	{
		for (size_t i = 0; i < 100; i++)
		{
			ideas[i] = src.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::addIdea(std::string idea)
{
	size_t i = 0;
	while (ideas[i] != "" && i < 100)
		i++;
	if (i < 100)
	{
		ideas[i] = idea;
		std::cout << "new idea: " << idea << std::endl;
	}
	else
	{
		std::cout << "brain full 🧠" << idea << std::endl;
	}
}

void Brain::printIdeas() const
{
	for (size_t i = 0; i < 100; i++)
	{
		if (ideas[i] != "")
			std::cout << ideas[i] << std::endl;
	}
}
