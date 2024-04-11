/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:32:57 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/11 14:51:12 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP


#include <algorithm>
#include <stdexcept>

template <typename T>
int& easyfind(T& array, int value)
{
	typename T::iterator iter = std::find(array.begin(), array.end(), value);
	if (iter == array.end())
		throw std::invalid_argument("value not found");
	return *iter;
}

#endif
