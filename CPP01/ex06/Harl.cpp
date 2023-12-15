/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:55:10 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/29 23:13:05 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	int index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			index = i;
			break;
		}
	}

	switch (index)
	{
		case 0:
			std::cout << "[ " << levels[0] << " ]" << std::endl;
			(this->*(functions[0]))();
			std::cout << std::endl;
		case 1:
			std::cout << "[ " << levels[1] << " ]" << std::endl;
			(this->*(functions[1]))();
			std::cout << std::endl;
		case 2:
			std::cout << "[ " << levels[2] << " ]" << std::endl;
			(this->*(functions[2]))();
			std::cout << std::endl;
		case 3:
			std::cout << "[ " << levels[3] << " ]" << std::endl;
			(this->*(functions[3]))();
			std::cout << std::endl;
			break;
		
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
