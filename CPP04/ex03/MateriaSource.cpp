/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:49:42 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/27 18:35:53 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		_materia_list[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (size_t i = 0; i < 4; i++)
	{
		_materia_list[i] = NULL;
	}
	*this = src;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_materia_list[i])
			delete _materia_list[i];
	}
}

MateriaSource& MateriaSource::operator =(const MateriaSource& src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (_materia_list[i])
			{
				delete _materia_list[i];
				_materia_list[i] = NULL;
			}
			if (src._materia_list[i])
				_materia_list[i] = src._materia_list[i]->clone();
		}
	}
	return *this;
}


void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << "Invalid materia." << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (!_materia_list[i])
		{
			_materia_list[i] = materia->clone();
			std::cout << "Materia of type " << materia->getType() << " added to source." << std::endl;
			return ;
		}
	}
	std::cout << "Source is full. Materia of type " << materia->getType() << " can't be learned." << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_materia_list[i] && _materia_list[i]->getType() == type)
		{
			AMateria* clone = _materia_list[i]->clone();
			std::cout << "Materia of type " << _materia_list[i]->getType() << " cloned from source." << std::endl;
			return clone;
		}
	}
	std::cout << "No materia of type " << type << " found in source." << std::endl;
	return NULL;
}
