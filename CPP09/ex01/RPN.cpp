/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:07:23 by fernacar          #+#    #+#             */
/*   Updated: 2024/05/08 20:11:33 by fernacar         ###   ########.fr       */
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
	while (!argStr.empty()) // iterate string
	{
		std::string elem = argStr.substr(0, 1);
		argStr = argStr.substr(1, argStr.size() - 1);
		if (elem == " ") // ignore if space
			continue ;
		if (elem.find_first_not_of("+-*/") != std::string::npos) // if not operator then push number to stack
			_stack.push(atol(elem.c_str()));
		else if (_stack.size() >= 2 && elem.length() == 1) // if not space or number then do operation, give error if no operator or operands
			doOperation(elem);
		else
		{
			std::cout << "Error" << std::endl;
			return;
		}
	}
	if (_stack.size() != 1 || !argStr.empty()) // give error if leftover numbers in stack
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
		std::cout << "unexpected operator" << std::endl;
	
	_stack.push(res);
}

RPN::RPN() {}
