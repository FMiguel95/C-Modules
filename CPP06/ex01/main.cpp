/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:54:38 by fernacar          #+#    #+#             */
/*   Updated: 2024/03/27 19:54:38 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
	Data d;
	std::cout << d << std::endl;

	uintptr_t raw = Serializer::serialize(&d);
	std::cout << "raw:" << raw << std::endl;

	Data* d_ptr = Serializer::deserialize(raw);
	std::cout << *d_ptr << std::endl;
}
