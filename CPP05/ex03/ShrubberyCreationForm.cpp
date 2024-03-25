/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:10:58 by fernacar          #+#    #+#             */
/*   Updated: 2024/03/25 19:10:58 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : Form(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		_target = src._target;
	}
	return *this;
}

void ShrubberyCreationForm::formEffect() const
{
	std::string filename = _target;
	std::ofstream outfile(filename.append("_shrubbery").c_str());
	for (int i = 0; i < 15; i++)
	{
		outfile <<
		"               ,@@@@@@@,                 " << std::endl <<
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.     " << std::endl <<
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    " << std::endl <<
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   " << std::endl <<
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   " << std::endl <<
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'    " << std::endl <<
		"   `&%\\ ` /%&'    |.|        \\ '|8'      " << std::endl <<
		"       |o|        | |         | |        " << std::endl <<
		"       |.|        | |         | |        " << std::endl <<
		"jgs  \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl <<
		std::endl;
	}
	outfile.close();
}
