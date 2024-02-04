/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:23 by fernacar          #+#    #+#             */
/*   Updated: 2024/02/04 17:04:57 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : _name(name), _grade(grade)
{
	try
	{
		if (_grade < 1)
			throw Bureaucrat::GradeTooHighException;
		else if (_grade > 150)
			throw Bureaucrat::GradeTooLowException;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade())
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException;
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException;
}

Bureaucrat::~Bureaucrat()
{

}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}


void Bureaucrat::incrementGrade()
{
	_grade--;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException;
}

void Bureaucrat::decrementGrade()
{
	_grade++;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException;
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
