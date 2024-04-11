/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:42:22 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/11 14:50:45 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP


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

	class ListFullException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	std::vector<int> _integers;
	unsigned int _n;

	Span();
};

#endif
