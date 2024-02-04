/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:14 by fernacar          #+#    #+#             */
/*   Updated: 2024/02/04 17:03:12 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

	private:
		const std::string _name;
		int _grade;

		Bureaucrat();
		Bureaucrat& operator = (const Bureaucrat& src);
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& bureaucrat);

#endif
