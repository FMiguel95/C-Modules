/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:54:07 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/14 23:06:21 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(Fixed x)
{
	if (x < 0)
		return x * -1;
	return x;
}

static Fixed triangle_area(Point const &a, Point const &b, Point const &c)
{
	return (((a.getX() * (b.getY() - c.getY())) +
			 (b.getX() * (c.getY() - a.getY())) +
			 (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point point)
{
	Fixed   abcArea = abs(triangle_area( a, b, c ));
	Fixed   pabArea = abs(triangle_area( point, a, b ));
	Fixed   pbcArea = abs(triangle_area( point, b, c ));
	Fixed   pcaArea = abs(triangle_area( point, c, a ));

	return  ( abcArea == pabArea + pbcArea + pcaArea &&
				pabArea != 0 && pbcArea != 0 && pcaArea != 0);
}
