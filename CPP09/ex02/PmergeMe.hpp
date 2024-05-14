/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:12:07 by fernacar          #+#    #+#             */
/*   Updated: 2024/05/08 20:24:53 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <vector>
# include <deque>
# include <algorithm>
# include <iostream>
# include <ctime>

class PmergeMe
{
public:
	PmergeMe(int ac, char**av);
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator =(const PmergeMe& src);
	~PmergeMe();

private:	
	std::vector<unsigned int> _vector;
	std::deque<unsigned int> _deque;

	typedef std::pair< std::vector<unsigned int>,std::vector<unsigned int> > pairVector;
	std::vector<unsigned int> sortVector();
	pairVector mergeSortPairsVector(pairVector pair);
	pairVector mergeVectors(pairVector p1, pairVector p2);

	typedef std::pair< std::deque<unsigned int>,std::deque<unsigned int> > pairDeque;
	std::deque<unsigned int> sortDeque();
	pairDeque mergeSortPairsDeque(pairDeque pair);
	pairDeque mergeDeques(pairDeque p1, pairDeque p2);

	PmergeMe();
};

#endif
