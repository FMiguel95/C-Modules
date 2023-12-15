/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:43:31 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/12 00:23:37 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: private ClapTrap
{
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& src);
		
		void attack(const std::string& target);
		void guardGate();

	private:
		ScavTrap();
};

#endif
