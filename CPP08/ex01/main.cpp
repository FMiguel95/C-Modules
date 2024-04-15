/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:06:27 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/15 14:06:31 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

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

	std::cout << ">> adding 10 numbers at once" << std::endl;
	sp = Span(20000);
	std::vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	sp.addNumber(v.begin(), v.end());
	std::cout << "sp.shortestSpan(): " << sp.shortestSpan() << std::endl;
	std::cout << "sp.longestSpan(): " << sp.longestSpan() << std::endl;

	std::cout << ">> adding 10000 more numbers at once..." << std::endl;
	for (size_t i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}
	sp.addNumber(v.begin(), v.end());
	std::cout << "sp.shortestSpan(): " << sp.shortestSpan() << std::endl;
	std::cout << "sp.longestSpan(): " << sp.longestSpan() << std::endl;

	std::cout << ">> adding too many numbers at once" << std::endl;
	sp = Span(123);
	v.erase(v.begin(), v.end());
	try
	{
		for (size_t i = 0; i < 300; i++)
		{
			v.push_back(i);
		}
		sp.addNumber(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "sp.shortestSpan(): " << sp.shortestSpan() << std::endl;
	std::cout << "sp.longestSpan(): " << sp.longestSpan() << std::endl;

	return 0;
}
