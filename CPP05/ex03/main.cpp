/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:30 by fernacar          #+#    #+#             */
/*   Updated: 2024/02/04 16:07:17 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat top("Bernie", 1);
	
	ShrubberyCreationForm s("home");
	top.signForm(s);
	top.executeForm(s);

	RobotomyRequestForm r("procedure");
	top.signForm(r);
	top.executeForm(r);

	PresidentialPardonForm p("that guy");
	top.signForm(p);
	top.executeForm(p);

}
