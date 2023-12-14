/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:54:09 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/14 00:15:16 by fernacar         ###   ########.fr       */
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
		(Fixed)x = src.x;
		(Fixed)y = src.y;
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
