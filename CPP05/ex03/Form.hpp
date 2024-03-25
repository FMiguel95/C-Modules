/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:23 by fernacar          #+#    #+#             */
/*   Updated: 2024/02/04 17:04:57 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string& name, const int& gradeReqSign, const int& gradeReqExec);
		Form(const Form& src);
		virtual ~Form();
		Form& operator = (const Form& src);

		const std::string getName() const;
		bool getSigned() const;
		int getGradeReqSign() const;
		int getGradeReqExec() const;
		void beSigned(const Bureaucrat& bureaucrat);
		void execute(const Bureaucrat& executor) const;
		virtual void formEffect() const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		Form();

		const std::string _name;
		bool _signed;
		const int _gradeReqSign;
		const int _gradeReqExec;
};

std::ostream& operator << (std::ostream& os, const Form& form);

#endif
