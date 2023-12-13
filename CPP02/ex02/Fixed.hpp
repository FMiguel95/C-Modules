/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:39:50 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/12 23:33:34 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int _rawBits;
		static const int frac_bits = 8;

	public:
		Fixed();
		Fixed( const Fixed &src );
		Fixed( const int src );
		Fixed( const float src );
		Fixed& operator =( const Fixed &src );
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;

		bool operator >( const Fixed &src );
		bool operator <( const Fixed &src );
		bool operator >=( const Fixed &src );
		bool operator <=( const Fixed &src );
		bool operator ==( const Fixed &src );
		bool operator !=( const Fixed &src );
		Fixed& operator +( const Fixed &src );
		Fixed& operator -( const Fixed &src );
		Fixed& operator *( const Fixed &src );
		Fixed& operator /( const Fixed &src );
		Fixed& operator ++();
		Fixed operator ++(int);
		Fixed& operator --();
		Fixed operator --(int);

		static Fixed& min( Fixed &f1, Fixed &f2 );
		static const Fixed& min( const Fixed &f1, const Fixed &f2 );
		static Fixed& max( Fixed &f1, Fixed &f2 );
		static const Fixed& max( const Fixed &f1, const Fixed &f2 );
};

std::ostream& operator <<( std::ostream &o, const Fixed &src );

#endif