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

int Span::shortestSpan() const
{
	if (_integers.size() < 2)
		throw NoSpanException();
	int span = 2147483647;
	for (std::vector<int>::const_iterator i = _integers.begin(); i != _integers.end(); ++i)
	{
		for (std::vector<int>::const_iterator j = i + 1; j != _integers.end(); ++j)
		{
			int temp = std::abs(*i - *j);
			if (temp < span)
				span = temp;
		}
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

void Span::addManyNumbers()
{

}

const char* Span::ListFullException::what() const throw()
{
	return "list is full";
}

const char* Span::NoSpanException::what() const throw()
{
	return "no span found";
}
