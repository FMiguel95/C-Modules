/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:38:07 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/27 20:23:46 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << ">> Correct Animals" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl;

	std::cout << ">> Wrong Animals" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	wrong_meta->makeSound();
	wrong_cat->makeSound();

	delete wrong_meta;
	delete wrong_cat;

	std::cout << std::endl;

	std::cout << ">> WrongCat sound" << std::endl;
	const WrongCat* wc = new WrongCat();
	wc->makeSound();

	delete wc;

	return 0;
}
