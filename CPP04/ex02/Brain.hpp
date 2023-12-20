/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:28:14 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/20 19:15:30 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& src);
		Brain& operator =(const Brain& src);
		~Brain();

		void addIdea(std::string idea);
		void printIdeas() const;
	
	private:
		std::string ideas[100];
};

#endif
