/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:54:09 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/14 22:05:01 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()) {}

Point::Point( const float x, const float y ) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point( const Point& src )
{
	*this = src;
}

Point& Point::operator =(const Point& src)
{
	if (this != &src)
	{
		const_cast<Fixed&>(x) = src.getX();
        const_cast<Fixed&>(y) = src.getY();
	}
	return *this;
}

Point::~Point()
{

}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}
