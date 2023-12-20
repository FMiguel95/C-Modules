/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:38:07 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 19:49:35 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << ">> Animal array" << std::endl;
	{
		Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
		for ( int i = 0; i < 4; i++ ) {
			delete animals[i];
		}
	}

	std::cout << std::endl;

	std::cout << ">> Stuff from subject" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}

	std::cout << std::endl;

	std::cout << ">> Deep copy" << std::endl;
	{
		Dog dog;
		dog.learn("first idea");
		{
			Dog tmp(dog);
			tmp.learn("temp idea");
			tmp.think();
		}
		dog.learn("second idea");
		dog.think();
	}

	std::cout << std::endl;

	return 0;
}
