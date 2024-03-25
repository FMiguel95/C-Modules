/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:30 by fernacar          #+#    #+#             */
/*   Updated: 2024/03/25 19:28:42 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Bernie", 1);
		
		ShrubberyCreationForm s("home");
		b1.signForm(s);
		b1.executeForm(s);

		RobotomyRequestForm r("procedure");
		b1.signForm(r);
		b1.executeForm(r);

		PresidentialPardonForm p("that guy");
		b1.signForm(p);
		b1.executeForm(p);

		// grade too low
		Bureaucrat b2("Barry", 150);
		b2.executeForm(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
