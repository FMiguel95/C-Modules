/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:39:50 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/07 19:47:47 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int _rawBits;
        static const int frac_bits = 8;

    public:
        Fixed();
        Fixed( const Fixed &src );
        Fixed& operator =( const Fixed &src );
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif