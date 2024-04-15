/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:42:30 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/15 13:55:09 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& src) : _integers(src._integers), _n(src._n) {}

Span& Span::operator =(const Span& src)
{
	if (this != &src)
	{
		_integers = src._integers;
		_n = src._n;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_integers.size() == _n)
		throw ListFullException();
	_integers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int distance = std::distance(begin, end);
	if (distance + _integers.size() > _n)
	{
		int excess = (distance + _integers.size()) - _n;
		_integers.insert(_integers.end(), begin, end - excess);
		throw ListFullException();
	}
	_integers.insert(_integers.end(), begin, end);
}

int Span::shortestSpan() const
{
	if (_integers.size() < 2)
		throw NoSpanException();
	std::vector<int>temp(_integers);
	std::sort(temp.begin(), temp.end());
	int span = 2147483647;
	for (std::vector<int>::iterator i = temp.begin(); i != temp.end() - 1; ++i)
	{
		int temp = std::abs(*i - *(i + 1));
		if (temp < span)
			span = temp;
	}
	return span;
}

int Span::longestSpan() const
{
	if (_integers.size() < 2)
		throw NoSpanException();
	int highestNumber = *std::max_element(_integers.begin(), _integers.end());
	int lowestNumber = *std::min_element(_integers.begin(), _integers.end());
	return highestNumber - lowestNumber;
}

const char* Span::ListFullException::what() const throw()
{
	return "list is full";
}

const char* Span::NoSpanException::what() const throw()
{
	return "no span found";
}
