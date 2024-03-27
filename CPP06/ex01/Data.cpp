/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:54:31 by fernacar          #+#    #+#             */
/*   Updated: 2024/03/27 19:54:32 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : c('w'), i(-24), f(3.14f), d(1.618) {}

Data::Data(const Data& src) : c(src.c), i(src.i), f(src.f), d(src.d) {}

Data::~Data() {}

Data& Data::operator =(const Data& src)
{
	if (this != &src)
	{
		c = src.c;
		i = src.i;
		f = src.f;
		d = src.d;
	}
	return *this;
}

char Data::getChar() const
{
	return c;
}

int Data::getInt() const
{
	return i;
}

float Data::getFloat() const
{
	return f;
}

double Data::getDouble() const
{
	return d;
}

std::ostream& operator <<(std::ostream &out, const Data& d)
{
	out << "c:" << d.getChar() << ", i:" << d.getInt() << ", f:" << d.getFloat() << ", d:" << d.getDouble();
	return out;
}
