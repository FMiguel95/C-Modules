#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>

class ScalarConverter
{
public:
	~ScalarConverter();

	static void convert(const std::string& literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator =(const ScalarConverter& src);

	static void convertFromChar(char c);
	static void convertFromInt(int i);
	static void convertFromFloat(float f);
	static void convertFromDouble(double d);
};

#endif
