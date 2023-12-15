/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:55:01 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/29 23:10:01 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return (1);
	}

	std::string level = av[1];
	Harl harl;
	harl.complain(level);
	return (0);
}
