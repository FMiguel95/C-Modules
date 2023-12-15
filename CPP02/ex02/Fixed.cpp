/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:40:03 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/14 23:26:20 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed( Fixed const &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( const int src )
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = src << frac_bits;
}

Fixed::Fixed( const float src )
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(src * (1 << frac_bits));
}

Fixed &Fixed::operator =( Fixed const &src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		_rawBits = src._rawBits;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	_rawBits = 0;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

int Fixed::toInt( void ) const
{
	return (_rawBits >> frac_bits);
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_rawBits) / (1 << frac_bits));
}

std::ostream &operator <<( std::ostream &o, const Fixed &src )
{
	o << src.toFloat();
	return (o);
}

bool Fixed::operator >( const Fixed &src ) const
{
	return (_rawBits > src.getRawBits());
}

bool Fixed::operator <( const Fixed &src ) const
{
	return (_rawBits < src.getRawBits());
}

bool Fixed::operator >=( const Fixed &src ) const
{
	return (_rawBits >= src.getRawBits());
}

bool Fixed::operator <=( const Fixed &src ) const
{
	return (_rawBits <= src.getRawBits());
}

bool Fixed::operator ==( const Fixed &src ) const
{
	return (_rawBits == src.getRawBits());
}

bool Fixed::operator !=( const Fixed &src ) const
{
	return (_rawBits != src.getRawBits());
}

Fixed Fixed::operator +( const Fixed &src ) const
{
	Fixed res;
	res.setRawBits(_rawBits + src.getRawBits());
	return res;
}

Fixed Fixed::operator -( const Fixed &src ) const
{
	Fixed res;
	res.setRawBits(_rawBits - src.getRawBits());
	return res;
}

Fixed Fixed::operator *( const Fixed &src ) const
{
	Fixed res;
	res.setRawBits(_rawBits * src.getRawBits() >> frac_bits);
	return res;
}

Fixed Fixed::operator /( const Fixed &src ) const
{
	Fixed res;
	res.setRawBits((_rawBits << frac_bits) / src.getRawBits());
	return res;
}

Fixed& Fixed::operator ++()
{
	++_rawBits;
	return *this;
}

Fixed Fixed::operator ++(int)
{
	Fixed copy( *this );
	_rawBits++;
	return copy;
}

Fixed& Fixed::operator --()
{
	--_rawBits;
	return *this;
}

Fixed Fixed::operator --(int)
{
	Fixed copy( *this );
	_rawBits--;
	return copy;
}

Fixed& Fixed::min( Fixed &f1, Fixed &f2 )
{
	return (f1 <= f2) ? f1 : f2;
}

const Fixed& Fixed::min( const Fixed &f1, const Fixed &f2 )
{
	return (f1 <= f2) ? f1 : f2;
}

Fixed& Fixed::max( Fixed &f1, Fixed &f2 )
{
	return (f1 >= f2) ? f1 : f2;
}

const Fixed& Fixed::max( const Fixed &f1, const Fixed &f2 )
{
	return (f1 >= f2) ? f1 : f2;
}
