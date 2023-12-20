/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:52:30 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 23:38:01 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& src);
		AMateria& operator =(const AMateria& src);
		virtual ~AMateria();

		virtual AMateria* clone() const = 0;
		const std::string& getType() const;
		virtual void use(ICharacter& target);
		
	protected:
		const std::string _type;
};

#endif
