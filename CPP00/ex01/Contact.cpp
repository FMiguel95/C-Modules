/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:28:25 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/28 21:57:41 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void	Contact::initContact(void)
{
	std::cout << std::endl << "Input first name> ";
	std::getline(std::cin, _firstName);
	std::cout << "Input last name> ";
	std::getline(std::cin, _lastName);
	std::cout << "Input nickname> ";
	std::getline(std::cin, _nickname);
	std::cout << "Input phone number> ";
	std::getline(std::cin, _phoneNumber);
	std::cout << "Input darkest secret> ";
	std::getline(std::cin, _secret);
	in_use = true;
	if (std::cin.eof())
	{
		std::cin.clear();
		return ;
	}
}

void	Contact::printField(std::string field) const
{
	if (field.length() > 10)
	{
		std::cout << field.substr(0, 9);
		std::cout << ".";
	}
	else
	{
		std::cout << std::setw(10) << field;
	}
}

void	Contact::printContactSimple(int index) const
{
	std::cout << std::setw(10) << index + 1 << "|";
	printField(_firstName);
	std::cout << "|";
	printField(_lastName);
	std::cout << "|";
	printField(_nickname);
	std::cout << std::endl;
}

void	Contact::printContactFull(void) const
{
	std::cout << std::setw(16) << "First name: " << _firstName << std::endl;
	std::cout << std::setw(16) << "Last name: " << _lastName << std::endl;
	std::cout << std::setw(16) << "Nickname: " << _nickname << std::endl;
	std::cout << std::setw(16) << "Phone number: " << _phoneNumber << std::endl;
	std::cout << std::setw(16) << "Darkest secret: " << _secret << std::endl;
}
