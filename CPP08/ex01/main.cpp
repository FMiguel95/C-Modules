#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	std::cout << ">> calling span function with no elements added" << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << ">> calling span function with 1 element added" << std::endl;
	sp.addNumber(6);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << ">> calling span functions with more elements added" << std::endl;
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "sp.shortestSpan(): " << sp.shortestSpan() << std::endl;
	std::cout << "sp.longestSpan(): " << sp.longestSpan() << std::endl;

	std::cout << ">> adding numbers past the limit" << std::endl;
	try
	{
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
