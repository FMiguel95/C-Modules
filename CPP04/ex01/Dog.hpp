/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:00:11 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 19:19:49 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& src);
		Dog& operator =(const Dog& src);
		~Dog();

		void makeSound() const;
		void learn(std::string idea);
		void think() const;

	private:
		Brain* brain;
};

#endif
