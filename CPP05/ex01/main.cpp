/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:30 by fernacar          #+#    #+#             */
/*   Updated: 2024/03/25 19:28:50 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// signing forms
	try
	{
		Bureaucrat b("Bernie", 100);
		
		Form f1("form 1", 100, 90);
		Form f2("form 2", 130, 120);
		Form f3("form 3",  50,  40);

		b.signForm(f1);
		b.signForm(f2);
		b.signForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// form grade too low
	try
	{
		Form f("a form", 100, 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// form grade too high
	try
	{
		Form f("another form", -3, 120);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
