/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:02:10 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/04 23:15:02 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <cstring>

BitcoinExchange::BitcoinExchange()
{
	// open price history file
	std::ifstream dataFile("data.csv");
	if (!dataFile)
	{
		std::cerr << "Error: could not open data.csv: " << std::strerror(errno) << std::endl;
		return ;
	}
	// for each line, get the date and value and add them to map
	for (std::string line; std::getline(dataFile, line); ) 
	{
		size_t commaPos = line.find_first_of(',');
		std::string date = line.substr(0, commaPos);
		float value = std::atof((line.substr(commaPos + 1, line.length() - commaPos)).c_str());
		_priceHistory.insert(std::pair<std::string,float>(date, value));
	}
	dataFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _priceHistory(src._priceHistory) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator =(const BitcoinExchange& src)
{
	if (this != &src)
	{
		_priceHistory = src._priceHistory;
	}
	return *this;
}

void BitcoinExchange::DisplayResult(char* inputArg) const
{
	// open input file
	std::ifstream inputFile(inputArg);
	if (!inputFile)
	{
		std::cerr << "Error: could not open " << inputArg << ": " << std::strerror(errno) << std::endl;
		return ;
	}
	// for each line, get the date and value and output the result
	for (std::string line; std::getline(inputFile, line); ) 
	{
		size_t commaPos = line.find_first_of('|');
		std::string date = line.substr(0, commaPos);
		float value = std::atof((line.substr(commaPos + 1, line.length() - commaPos)).c_str());
	}
	inputFile.close();
}
