/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:44:36 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/19 23:34:42 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& src);
		virtual ~Animal();
		Animal& operator =(const Animal& src);

		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

#endif
