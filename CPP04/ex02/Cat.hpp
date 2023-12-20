/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:04:47 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 20:00:20 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat& src);
		Cat& operator =(const Cat& src);
		~Cat();

		void makeSound() const;
		void learn(std::string idea);
		void think() const;

	private:
		Brain* brain;
};

#endif
