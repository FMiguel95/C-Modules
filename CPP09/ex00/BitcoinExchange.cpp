/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:02:10 by fernacar          #+#    #+#             */
/*   Updated: 2024/05/08 19:56:18 by fernacar         ###   ########.fr       */
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
		_hasDatabase = false;
		std::cerr << "Error: could not open data.csv: " << std::strerror(errno) << std::endl;
		return ;
	}
	_hasDatabase = true;
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

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _priceHistory(src._priceHistory), _hasDatabase(src._hasDatabase) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator =(const BitcoinExchange& src)
{
	if (this != &src)
	{
		_priceHistory = src._priceHistory;
		_hasDatabase = src._hasDatabase;
	}
	return *this;
}

bool BitcoinExchange::getHasDatabase() const
{
	return _hasDatabase;
}

bool BitcoinExchange::ValidateDate(const std::string& dateStr) const
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
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
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

float BitcoinExchange::GetPrice(const std::string& dateStr) const
{
	std::map<std::string, float>::const_iterator i = _priceHistory.upper_bound(dateStr);
	if (i != _priceHistory.begin())
		i--;
	return i->second;
}

bool BitcoinExchange::ValidateValue(const std::string& amountStr) const
{
	size_t i = 0;
	bool decimalDelFound = false;
	if (amountStr[i] == '-') // skip the minus sign for now, it will be tested later
		i++;
	while (amountStr[i])
	{
		if (!std::isdigit(amountStr[i]) && amountStr[i] != '.') // if its not a digit or a .
			return false;
		if (amountStr[i] == '.')
		{
			if (i == 0) // if . is right at the start
				return false;
			if (!std::isdigit(amountStr[i + 1])) // if there isnt a number after a .
				return false;
			if (decimalDelFound) // if more than one . was found
				return false;
			decimalDelFound = true;
		}
		i++;
	}
	return true;
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
	std::string line;
	std::getline(inputFile, line); // skip first line
	while (std::getline(inputFile, line)) 
	{
		// get delimiter position
		size_t delimiterPos = line.find("|");
		if (delimiterPos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		// get date
		size_t dateEndPos = delimiterPos;
		if (dateEndPos != 0)
			dateEndPos--;
		while (dateEndPos > 0 && std::isspace(line[dateEndPos]))
			dateEndPos--;
		std::string dateStr = line.substr(0, dateEndPos+1);
		if (!ValidateDate(dateStr))
		{
			std::cout << "Error: invalid date format => " << line << std::endl;
			continue;
		}

		// get amount
		size_t valueStartPos = delimiterPos + 1;
		while (line[valueStartPos] && std::isspace(line[valueStartPos]))
			valueStartPos++;
		size_t valueEndPos = line.length() - 1;
		while (valueEndPos > 0 && std::isspace(line[valueEndPos]))
			valueEndPos--;
		std::string amountStr = line.substr(valueStartPos, valueEndPos + 1 - valueStartPos);
		if (!ValidateValue(amountStr))
		{
			std::cout << "Error: bad number format." << std::endl;
			continue;
		}
		float amount = std::atof(amountStr.c_str());
		if (amount <= 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (amount > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		
		float converstion = amount * GetPrice(dateStr);
		std::cout << dateStr << " => " << amountStr << " = " << converstion << std::endl;
	}
	inputFile.close();
}
