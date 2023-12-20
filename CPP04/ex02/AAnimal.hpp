/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:44:36 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:08 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal& src);
		virtual ~AAnimal();
		virtual AAnimal& operator =(const AAnimal& src);

		virtual void makeSound() const = 0;
		std::string getType() const;

	protected:
		std::string type;
};

#endif
