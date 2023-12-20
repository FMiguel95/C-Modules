/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:06:15 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 22:06:50 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const std::string& type);
		Cure(const Cure& src);
		// Cure& operator =(const Cure& src);
		~Cure();

		Cure* clone() const;
		void use(ICharacter& target);

	private:
		
};

#endif
