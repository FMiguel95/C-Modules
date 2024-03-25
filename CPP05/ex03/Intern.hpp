/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:09:50 by fernacar          #+#    #+#             */
/*   Updated: 2024/03/25 19:12:59 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();
		Intern& operator = (const Intern& src);

		Form* makeForm(std::string formName, std::string formTarget);
	
	private:
		Form* makeShrubberyCreationForm(const std::string& target);
		Form* makeRobotomyRequestForm(const std::string& target);
		Form* makePresidentialPardonForm(const std::string& target);
};

#endif
