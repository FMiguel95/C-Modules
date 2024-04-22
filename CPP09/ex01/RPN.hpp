/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:07:26 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/04 21:07:26 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <cmath>

class RPN
{
public:
	RPN(std::string argStr);
	RPN(const RPN& src);
	RPN& operator =(const RPN& src);
	~RPN();

private:
	std::stack<long> _stack;

	std::string getNextElem(std::string& argStr);
	void doOperation(const std::string& op);
	RPN();
};

#endif
