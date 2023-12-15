/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:07:41 by fernacar          #+#    #+#             */
/*   Updated: 2023/10/23 00:17:55 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	
	public:
		HumanB( std::string name );
		~HumanB();

		void attack();
		void setWeapon( Weapon &weapon );
};

#endif