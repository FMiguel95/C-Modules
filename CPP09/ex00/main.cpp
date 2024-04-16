/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:02:16 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/10 12:07:13 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc <input file>" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.DisplayResult(av[1]);
	
	return 0;
}
