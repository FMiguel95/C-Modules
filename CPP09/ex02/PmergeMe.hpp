/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:12:07 by fernacar          #+#    #+#             */
/*   Updated: 2024/04/30 18:58:25 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <vector>
# include <deque>
# include <algorithm>
# include <iostream>

class PmergeMe
{
public:
	PmergeMe(int ac, char**av);
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator =(const PmergeMe& src);
	~PmergeMe();
	
	std::vector<unsigned int> sortVector() ;
	std::deque<unsigned int> sortDeque() const;

	template <typename T>
	void print_list(T& list)
	{
		for (typename T::iterator i = list.begin(); i != list.end(); ++i)
		{
			std::cout << *i << std::endl;
		}
	}
	
private:
	int _comp;
	typedef std::pair< std::vector<unsigned int>,std::vector<unsigned int> > pairVector;
	
	std::vector<unsigned int>_vector;
	std::deque<unsigned int>_deque;

	pairVector mergeSortPairsVector(pairVector pair) ;
	pairVector mergeVectors(pairVector p1, pairVector p2) ;

	PmergeMe();
	
};

#endif
