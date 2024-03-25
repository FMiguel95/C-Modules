/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:09:53 by fernacar          #+#    #+#             */
/*   Updated: 2024/03/25 19:27:07 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern::~Intern() {}

Intern& Intern::operator = (const Intern& src)
{
	(void)src;
	return *this;
}

Form* Intern::makeForm(std::string formName, std::string formTarget)
{
	Form* (Intern::*functions[3])(const std::string& target) = { &Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm };
	std::string formNames[3] = { "Shrubbery Creation", "Robotomy Request", "Presidential Pardon" };
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			return (this->*(functions[i]))(formTarget);
		}
	}
	std::cerr << "Unknown form name." << std::endl;
	return NULL;
}

Form* Intern::makeShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::makeRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

Form* Intern::makePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}
