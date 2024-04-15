/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:49:31 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/15 14:06:10 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

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
	std::list<int>::iterator it_list = list.begin();
	MutantStack<int>::iterator ite_ms = mstack.end();
	std::list<int>::iterator ite_list = list.end();
	++it_ms;
	++it_list;
	--ite_ms;
	--ite_list;
	
	std::cout << ">> mstack iterate" << std::endl;
	for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	std::cout << ">> list iterate" << std::endl;
	for (std::list<int>::iterator i = list.begin(); i != list.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	std::cout << ">> create stack from mutant stack" << std::endl;
	std::stack<int> stack(mstack);
	std::cout << ">> change stack" << std::endl;
	stack.pop();
	std::cout << ">> original is not affected" << std::endl;
	std::cout << "mstack.top: " << mstack.top() << std::endl;
	std::cout << "stack.top: " << stack.top() << std::endl;

	std::cout << ">> assignment operator" << std::endl;
	MutantStack<int> mstack2 = mstack;
	mstack2.pop();
	std::cout << ">> original is not affected" << std::endl;
	std::cout << "mstack.top: " << mstack.top() << std::endl;
	std::cout << "mstack2.top: " << mstack2.top() << std::endl;

	std::cout << ">> copy constructor" << std::endl;
	MutantStack<int> mstack3(mstack2);
	mstack3.pop();
	std::cout << ">> original is not affected" << std::endl;
	std::cout << "mstack.top: " << mstack.top() << std::endl;
	std::cout << "mstack2.top: " << mstack2.top() << std::endl;
	std::cout << "mstack3.top: " << mstack3.top() << std::endl;
	
	return 0;
}
