/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:02:10 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/16 18:53:52 by fernacar         ###   ########.fr       */
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
	std::string line;
	std::getline(dataFile, line); // skip first line
	while (std::getline(dataFile, line)) 
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

static bool ValidateDate(const std::string& dateStr)
{
	size_t dateDelimiter1 = dateStr.find("-");
	size_t dateDelimiter2 = dateStr.find_last_of("-");
	// validate date delimiters
	if (dateDelimiter1 == std::string::npos || dateDelimiter1 == dateDelimiter2)
		return false;

	std::string yearStr = dateStr.substr(0, dateDelimiter1);
	std::string monthStr = dateStr.substr(dateDelimiter1 + 1, dateDelimiter2 - dateDelimiter1 - 1);
	std::string dayStr = dateStr.substr(dateDelimiter2 + 1, dateStr.length() - dateDelimiter2 + 1);
	// validate characters are only numbers
	if (yearStr.find_first_not_of("0123456789") != std::string::npos || monthStr.find_first_not_of("0123456789") != std::string::npos || dayStr.find_first_not_of("0123456789") != std::string::npos)
		return false;

	long year = std::atol(yearStr.c_str());
	long month = std::atol(monthStr.c_str());
	long day = std::atol(dayStr.c_str());
	// validate ranges
	if (year < 1 || month < 0 || month > 12 || day < 0 || day > 31)
		return false;
	
	// validate 30 day months
	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	
	// validate leap years
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 29)
		return false;

	// validate february
	if (month == 2 && !((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 28)
		return false;

	return true;
}

void BitcoinExchange::DisplayResult(char* inputArg) const
{
	// for (std::_Rb_tree_const_iterator<std::pair<const std::string, float> > i = _priceHistory.begin(); i != _priceHistory.end(); ++i)
	// {
	// 	std::cout << i->first << " " << i->second << std::endl;
	// }
	// (void)inputArg;
	
	// open input file
	std::ifstream inputFile(inputArg);
	if (!inputFile)
	{
		std::cerr << "Error: could not open " << inputArg << ": " << std::strerror(errno) << std::endl;
		return ;
	}
	// for each line, get the date and value and output the result
	std::string line;
	std::getline(inputFile, line); // skip first line
	while (std::getline(inputFile, line)) 
	{
		size_t delimiterPos = line.find(" | ");
		if (delimiterPos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		// get date
		std::string dateStr = line.substr(0, delimiterPos);
		// std::cout << dateStr << std::endl;
		if (!ValidateDate(dateStr))
		{
			std::cout << "Error: invalid date format => " << line << std::endl;
			continue;
		}

		// get amount
		std::string amountStr = line.substr(delimiterPos + 3, line.length() - delimiterPos);
		// std::cout << amountStr << std::endl;
		float amount = std::atof(amountStr.c_str());
		if (amount < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (amount > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		
		// TODO fix it
		float converstion = amount * _priceHistory.upper_bound(dateStr)->second;
		std::cout << dateStr << " => " << amount << " = " << converstion << " (" << amount << "*" << _priceHistory.lower_bound(dateStr)->second << ")" << "from " << _priceHistory.lower_bound(dateStr)->first << std::endl;
	}

	std::cout << 1.0 * 0.32f << std::endl;
	inputFile.close();
}
