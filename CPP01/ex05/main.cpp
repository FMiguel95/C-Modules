/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:55:01 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/29 22:47:20 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "> harl.complain(\"DEBUG\");" << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl;

	std::cout << "> harl.complain(\"INFO\");" << std::endl;
	harl.complain("INFO");

	std::cout << std::endl;

	std::cout << "> harl.complain(\"WARNING\");" << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl;

	std::cout << "> harl.complain(\"ERROR\");" << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl;

	std::cout << "> harl.complain(\"AAAHHH\");" << std::endl;
	harl.complain("AAAHHH");
}
