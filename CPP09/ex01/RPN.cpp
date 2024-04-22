/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:07:23 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/04 21:07:38 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string argStr)
{
	if (argStr.find_first_not_of("0123456789+-*/ ") != std::string::npos)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	while (!argStr.empty())
	{
		std::string elem = getNextElem(argStr);
		if (elem.empty())
			continue ;
		else if (elem.find_first_not_of("+-*/") != std::string::npos)
			_stack.push(atol(elem.c_str()));
		else if (_stack.size() >= 2 && elem.length() == 1)
			doOperation(elem);
		else
			break;
	}
	if (_stack.size() != 1 || !argStr.empty())
		std::cout << "Error" << std::endl;
	else
		std::cout << _stack.top() << std::endl;
}

RPN::RPN(const RPN& src) : _stack(src._stack) {}

RPN& RPN::operator =(const RPN& src)
{
	if (this != &src)
	{
		_stack = src._stack;
	}
	return *this;
}

RPN::~RPN() {}

std::string RPN::getNextElem(std::string& argStr)
{
	size_t pos = argStr.find(" ");
	std::string elem = argStr.substr(0, pos);
	if (pos != std::string::npos)
		argStr = argStr.substr(pos + 1);
	else
		argStr.clear();
	return elem;
}

void RPN::doOperation(const std::string& op)
{
	long operand2 = _stack.top();
	_stack.pop();
	long operand1 = _stack.top();
	_stack.pop();

	long res;
	if (op == "+")
		res = operand1 + operand2;
	else if (op == "-")
		res = operand1 - operand2;
	else if (op == "*")
		res = operand1 * operand2;
	else if (op == "/")
		res = operand1 / operand2;
	else
		std::cout << "lol" << std::endl;
	
	_stack.push(res);
}

RPN::RPN() {}
