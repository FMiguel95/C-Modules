/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:10:49 by fernacar          #+#    #+#             */
/*   Updated: 2024/03/25 19:10:50 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Form(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		_target = src._target;
	}
	return *this;
}

void PresidentialPardonForm::formEffect() const
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
