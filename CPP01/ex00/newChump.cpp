/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newChump.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:46:18 by fernacar          #+#    #+#             */
/*   Updated: 2023/10/22 20:01:55 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void randomChump( std::string name )
{
	Zombie chump(name);
	chump.announce();
}