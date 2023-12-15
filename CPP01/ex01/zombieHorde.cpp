/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:16:13 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/29 19:21:38 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N] ;

	for (int i = 0; i < N; i++)
	{
		horde[i].SetName(name);
	}

	return (horde);
}
