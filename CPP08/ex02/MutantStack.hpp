/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:05:02 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/10 14:08:05 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <vector>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : ;
	MutantStack(const MutantStack& src);
	MutantStack& operator =(const MutantStack& src);
	~MutantStack();

	std::vector<T> _list;

};
