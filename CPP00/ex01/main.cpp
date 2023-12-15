/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:39:58 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/28 21:57:10 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	pb;
	std::string	instruction;
	
	pb.init();
	while (1)
	{
		std::cout << std::endl << "\e[0mType \e[1;96mADD\e[0m, \e[1;96mSEARCH\e[0m or \e[1;96mEXIT\e[0m> ";
		std::getline(std::cin, instruction);

		if (instruction.compare("ADD") == 0)
			pb.addContact();
		else if (instruction.compare("SEARCH") == 0)
			pb.searchContact();
		else if (instruction.compare("EXIT") == 0 || std::cin.eof())
			break ;
		else
			std::cout << "\e[1;91mInvalid instruction!\e[0m" << std::endl;
	}
	std::cout << "Closing phonebook..." << std::endl;
	return (0);
}
