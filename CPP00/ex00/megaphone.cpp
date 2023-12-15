/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:42:13 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/23 19:56:29 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		for (size_t j = 0; j < arg.length(); j++)
			arg[j] = std::toupper(arg[j]);
		std::cout << arg;
	}
	std::cout << std::endl;
	return (0);
}
