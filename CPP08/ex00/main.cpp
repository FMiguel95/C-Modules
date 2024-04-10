/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:32:47 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/10 13:38:35 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
	std::vector<int> vector;
	std::list<int> list;
	std::deque<int> deque;
	for (size_t i = 0; i < 5; i++)
	{
		vector.push_back(i);
		list.push_back(i);
		deque.push_back(i);
	}

	easyfind(vector, 1) = 99;
	for (std::vector<int>::iterator i = vector.begin(); i != vector.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;
	
	easyfind(list, 2) = 99;
	for (std::list<int>::iterator i = list.begin(); i != list.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;
	
	easyfind(deque, 3) = 99;
	for (std::deque<int>::iterator i = deque.begin(); i != deque.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;

	try
	{
		easyfind(list, -3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
