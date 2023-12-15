/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:44:26 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/29 19:32:33 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "> &str" << std::endl;
	std::cout << &str << std::endl;
	std::cout << "> stringPTR" << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << "> &stringREF" << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "> str" << std::endl;
	std::cout << str << std::endl;
	std::cout << "> *stringPTR" << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << "> stringREF" << std::endl;
	std::cout << stringREF << std::endl;

	return (0);
}