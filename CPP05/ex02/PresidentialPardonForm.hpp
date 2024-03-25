/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:23 by fernacar          #+#    #+#             */
/*   Updated: 2024/02/04 17:04:57 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "Form.hpp"
# include <string>

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator = (const PresidentialPardonForm& src);

		void formEffect() const;

	private:
		PresidentialPardonForm();

		std::string _target;

};

#endif
