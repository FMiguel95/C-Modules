/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:30 by fernacar          #+#    #+#             */
/*   Updated: 2024/03/25 19:28:12 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b("Bruno", 1);
		Intern i;
		
		Form* f = i.makeForm("Presidential Pardon", "Some guy");
		b.signForm(*f);
		b.executeForm(*f);
		delete f;

		f = i.makeForm("blabla", "???");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
