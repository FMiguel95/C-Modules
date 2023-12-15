/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:07:21 by fernacar          #+#    #+#             */
/*   Updated: 2023/10/23 00:03:20 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	
	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA();

		void attack();
};

#endif