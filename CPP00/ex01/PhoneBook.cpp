/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:28:35 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/28 22:11:41 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

#include <limits>

void	PhoneBook::init()
{
	for (size_t i = 0; i < 8; i++)
	{
		_contacts[i].in_use = 0;
	}
}

void	PhoneBook::addContact(void)
{
	int	next_contact_index = 0;
	for (next_contact_index = 0; next_contact_index < 8; next_contact_index++)
	{
		if (_contacts[next_contact_index].in_use == false)
			break ;
	}
	if (next_contact_index >= 8)
	{
		for (int i = 1; i < 8; i++)
		{
			_contacts[i - 1] = _contacts[i];
		}
		next_contact_index = 7;
	}
	_contacts[next_contact_index].initContact();
	std::cout << "\e[1mContact added!\e[0m" << std::endl;
}

int		PhoneBook::my_str2int(std::string input) const
{
	long	ret = 0;
	int 	sign = 1;
	int 	i = 0;

	while (input[i] == ' ')
		i++;
	if (input[i] == '+' || input[i] == '-')
	{
		if (input[i] == '-')
			sign = -1;
		i++;
	}
	while (input[i])
	{
		if (input[i] >= '0' && input[i] <= '9')
			ret = ret * 10 + input[i] - '0';
		else
			return (0);
		if (ret * sign < -2147483648 || ret * sign > 2147483647)
			return (0);
		i++;
	}
	return ((long)(ret * sign));
}

void	PhoneBook::searchContact(void) const
{
	if (isEmpty())
	{
		std::cout << std::endl << "Your phonebook is empty. \e[1mHow sad!\e[0m" << std::endl;
		return ;
	}
	
	std::cout << std::endl << "     Entry|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (_contacts[i].in_use)
			_contacts[i].printContactSimple(i);
	}
	
	std::string	input;
	int index;
	do
	{
		std::cout << "Index of entry to display> ";
		std::getline(std::cin, input);
		index = my_str2int(input);
		if (std::cin.eof())
		{
			std::cin.clear();
			break;
		}
		if (index <= 0 || index > 8 || _contacts[index - 1].in_use == false)
		{
			std::cout << "\e[1;91mInvalid entry.\e[0m" << std::endl;
			continue ;
		}
	} while (index <= 0 || index > 8 || _contacts[index - 1].in_use == false);
	if (!(index <= 0 || index > 8 || _contacts[index - 1].in_use == false))
		_contacts[index - 1].printContactFull();
}

bool	PhoneBook::isEmpty(void) const
{
	for (size_t i = 0; i < 8; i++)
	{
		if (_contacts[i].in_use == true)
			return (false);
	}
	return (true);
}
