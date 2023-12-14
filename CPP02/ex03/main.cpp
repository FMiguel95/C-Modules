/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:31:16 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/14 00:21:16 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a(0,0);
	Point b(0,1);
	Point c(1,0);
	Point p(0.4f,0.4f);

	bool res = bsp(a, b, c, p);
	std::cout << "is inside: " << res << std::endl;

	return 0;
}
