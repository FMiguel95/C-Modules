/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:49:31 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/11 15:47:20 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> list;

	std::cout << ">> fill lists..." << std::endl;
	mstack.push(5);
	list.push_back(5);
	mstack.push(17);
	list.push_back(17);
	
	std::cout << "mstack top: " << mstack.top() << std::endl;
	std::cout << "list back: " << list.back() << std::endl;
	
	std::cout << ">> pop..." << std::endl;
	mstack.pop();
	list.pop_back();
	
	std::cout << "mstack size: " << mstack.size() << std::endl;
	std::cout << "list size: " << list.size() << std::endl;
	
	std::cout << ">> fill lists..." << std::endl;
	mstack.push(3);
	list.push_back(3);
	mstack.push(5);
	list.push_back(5);
	mstack.push(737);
	list.push_back(737);
	mstack.push(0);
	list.push_back(0);
	
	MutantStack<int>::iterator it_ms = mstack.begin();
	MutantStack<int>::iterator it_list = mstack.begin();
	MutantStack<int>::iterator ite_ms = mstack.end();
	MutantStack<int>::iterator ite_list = mstack.end();
	
	++it_ms;
	++it_list;
	--ite_ms;
	--ite_list;
	
	std::cout << ">> mstack iterate" << std::endl;
	while (it_ms != ite_ms)
	{
		std::cout << *it_ms << std::endl;
		++it_ms;
	}
	std::cout << ">> list iterate" << std::endl;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}

	std::stack<int> s(mstack);

	return 0;
}
