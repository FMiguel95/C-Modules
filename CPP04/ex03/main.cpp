/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:33:31 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/27 00:42:58 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	Ice templateIce;
	Cure templateCure;
	MateriaSource materiaSource;

	std::cout << ">> Adding materias to source" << std::endl;
	materiaSource.learnMateria(&templateIce);
	materiaSource.learnMateria(&templateCure);
	materiaSource.learnMateria(&templateCure);
	materiaSource.learnMateria(&templateIce);
	materiaSource.learnMateria(&templateIce);
	materiaSource.learnMateria(&templateCure);

	std::cout << std::endl;

	std::cout << ">> Creating characters" << std::endl;
	Character character1("Cloud");
	Character character2("Barret");
	Character character3("Tifa");

	std::cout << std::endl;

	std::cout << ">> Equipping materias" << std::endl;
	AMateria *mat1 = materiaSource.createMateria("ice");
	AMateria *mat2 = materiaSource.createMateria("ice");
	AMateria *mat3 = materiaSource.createMateria("cure");
	AMateria *mat4 = materiaSource.createMateria("cure");
	AMateria *mat5 = materiaSource.createMateria("cure");
	character1.equip(mat1);
	character1.equip(mat1);
	character1.equip(mat2);
	character1.equip(mat3);
	character1.equip(mat4);
	character1.equip(mat5);
	character1.unequip(0);
	character1.unequip(0);
	character1.unequip(5);
	character1.equip(mat5);
	character1.unequip(0);
	character1.unequip(3);
	delete mat1;
	delete mat4;
	delete mat5;

	std::cout << std::endl;

	std::cout << ">> Using materias" << std::endl;
	character1.use(0, character2);
	character1.use(1, character2);
	character1.use(2, character1);
	character1.use(5, character2);

	std::cout << std::endl;

	std::cout << ">> Copying characters" << std::endl;
	character1 = character2;
	character2.equip(materiaSource.createMateria("ice"));
	character1.use(0, character3);
	character2.use(0, character3);
	Character temp(character2);
	temp.use(0, character3);
	character2.equip(materiaSource.createMateria("cure"));
	temp.use(0, character3);

	std::cout << std::endl;

	return 0;
}
