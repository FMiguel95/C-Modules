/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:23:59 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/23 21:44:33 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{

private:
	Contact _contacts[8];

	int		my_str2int(std::string input) const;
	
public:
	void	init(void);
	void	addContact(void);
	void	searchContact(void) const;
	bool	isEmpty(void) const;
};

#endif
