/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:45:33 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/29 19:05:43 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "iostream"

Zombie	*newZombie( std::string name );
void randomChump( std::string name );

int	main(void)
{
	std::cout << ">>> stack allocation" << std::endl;
	std::cout << "> randomChump(\"Foo\");" << std::endl;
	randomChump("Foo");

	std::cout << std::endl;

	std::cout << ">>> heap allocation" << std::endl;
	std::cout << "> Zombie *zombie = newZombie(\"Fii\");" << std::endl;
	Zombie *zombie = newZombie("Fii");
	zombie->announce();
	std::cout << "> delete zombie;" << std::endl;
	delete zombie;

	return (0);
}