#include "ScalarConverter.hpp"
#include <iomanip>
#include <cstdlib>
#include <climits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
}

ScalarConverter& ScalarConverter::operator =(const ScalarConverter& src)
{
	(void)src;
	return *this;
}

void ScalarConverter::convert(const std::string& literal)
{
	bool error = false;

	// check for char
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		convertFromChar(literal[0]);
		return ;
	}

	// check for int
	// every character is a number
	long temp = 0;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && literal[0] == '-' && literal.length() > 1)
			i++;
		if (!std::isdigit(literal[i]))
		{
			error = true;
			break;
		}
		temp = temp * 10 + literal[i] - '0';
		if ((literal[0] != '-' && temp > INT_MAX) || (literal[0] == '-' && -temp < INT_MIN))
		{
			error = true;
			break;
		}
	}
	if (!error)
	{
		if (literal[0] == '-')
			temp = -temp;
		convertFromInt((int)temp);
		return;
	}
	if (literal.find('f') != std::string::npos || literal == "+inff" || literal == "-inff" || literal == "nanf")
	{
		convertFromFloat(std::atof(literal.c_str()));
		return;
	}
}

void ScalarConverter::convertFromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << (int)c << std::endl;
	std::cout << "float: " << (float)c << ".0f" << std::endl;
	std::cout << "double: " << (double)c << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int i)
{
	// print char
	if (i < CHAR_MIN || i > CHAR_MAX)
		std::cout << "char: Impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << (char)i << "'" << std::endl;

	// print int
	std::cout << "int: " << i << std::endl;

	// calculate precision
	long temp = std::labs(i);
	int len = 2;
	while (temp >= 10)
	{
		len++;
		temp /= 10;
	}
	std::cout << std::showpoint << std::setprecision(len);

	// print float
	std::cout << "float: "  << (float)i << "f" << std::endl;
	
	// print double
	std::cout << "double: " << (double)i << std::endl;
}

void ScalarConverter::convertFromFloat(float f)
{
	// print char
	if (f < CHAR_MIN || f > CHAR_MAX)
		std::cout << "char: Impossible" << std::endl;
	else if (f != f && !std::isprint(f))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << (char)f << "'" << std::endl;

	// print int
	if (f < INT_MIN || f > INT_MAX)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << (int)f << std::endl;

	// print float
	std::cout << "float: "  << f << "f" << std::endl;
	
	// print double
	std::cout << "double: " << (double)f << std::endl;
}

// void ScalarConverter::convertFromDouble(double d)
// {

// }
