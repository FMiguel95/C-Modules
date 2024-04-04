#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span& src);
	Span& operator =(const Span& src);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	void addManyNumbers();

	class ListFullException : std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	std::vector<int> _integers;
	unsigned int _n;

	Span();
};
