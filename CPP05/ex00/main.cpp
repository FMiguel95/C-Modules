/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:30 by fernacar          #+#    #+#             */
/*   Updated: 2024/02/04 16:07:17 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("Bernie", 100);
	std::cout << b1 << std::endl;

	Bureaucrat b2("Barnie", 160);

	Bureaucrat b3("Billy", 0);
}
