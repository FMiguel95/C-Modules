/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:12:15 by fernacar          #+#    #+#             */
/*   Updated: 2024/05/02 20:16:55 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

PmergeMe::PmergeMe(int ac, char**av)
{
	for (int i = 1; i < ac; i++)
	{
		int number = std::atoi(av[i]);
		// std::cout << number << std::endl;
		_vector.push_back(number);
		_deque.push_back(number);
	}	
}

PmergeMe::PmergeMe(const PmergeMe& src) : _vector(src._vector), _deque(src._deque) {}

PmergeMe& PmergeMe::operator =(const PmergeMe& src)
{
	if (this != &src)
	{
		_vector = src._vector;
		_deque = src._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<unsigned int> PmergeMe::sortVector()
{
	clock_t start = clock();
	_comp = 0;
	// save and remove last element if odd number
	std::vector<unsigned int>::const_iterator straggler;
	if (_vector.size() % 2)
		straggler = _vector.end() - 1;
	else
		straggler = _vector.end();

	// create list of pairs
	pairVector pair;
	for (size_t i = 0; i < _vector.size() / 2; i++)
	{
		pair.first.push_back(_vector[i * 2]);
		pair.second.push_back(_vector[i * 2 + 1]);
	}
	// std::cout << ">>> pairs" << std::endl;
	// for (size_t i = 0; i < _vector.size() / 2; i++)
	// 	std::cout << pair.first[i] << " : " << pair.second[i] << std::endl;
		
	// for each pair compare elements and sort them
	for (size_t i = 0; i < _vector.size() / 2; i++)
	{
		_comp++;
		if (pair.first[i] > pair.second[i])
		{
			unsigned int temp = pair.first[i];
			pair.first[i] = pair.second[i];
			pair.second[i] = temp;
		}
	}
	std::cout << ">>> pairs after sort" << std::endl;
	// for (size_t i = 0; i < _vector.size() / 2; i++)
	// 	std::cout << pair.first[i] << " : " << pair.second[i] << std::endl;
	
	// recursively sort pairs based on largest element
	std::cout << ">>> merge sort" << std::endl;
	pair = mergeSortPairsVector(pair);
	// for (size_t i = 0; i < _vector.size() / 2; i++)
	// 	std::cout << pair.first[i] << " : " << pair.second[i] << std::endl;

	// send smallest member of pend to the start of main
	pair.second.insert(pair.second.begin(), pair.first[0]);
	pair.first.erase(pair.first.begin());
	// std::cout << ">>> smallest member of pend to start of main" << std::endl;
	// for (size_t i = 0; i < pair.second.size(); i++)
	// 	std::cout << pair.second[i] << std::endl;

	// std::cout << ">>> the pend btw" << std::endl;
	// for (size_t i = 0; i < pair.first.size(); i++)
	// 	std::cout << pair.first[i] << std::endl;
	
	// order pend for best insertion sequence
	//
	//
	//// create list of pend numbers and their main pair
	std::vector<unsigned int> main = pair.second;
	std::vector< std::pair<unsigned int, unsigned int> > pend;
	for (size_t i = 0; i < pair.first.size(); i++)
	{
		std::pair<unsigned int, unsigned int> temp;
		temp.first = pair.first[i];
		temp.second = pair.second[i + 2];
		pend.push_back(temp);
	}
	// std::cout << ">>> more pend info" << std::endl;
	// for (size_t i = 0; i < pair.first.size(); i++)
	// 	std::cout << pend[i].first << "(paired with " << pend[i].second << ")" << std::endl;

	//// create list of lists of pairs of numbers/numbers 😩
	std::vector<std::vector< std::pair<unsigned int, unsigned int> > > super_pend;
	//// fill the list with the best insertion order
	unsigned int prev_amount = 0;
	unsigned int new_amount = 2;
	unsigned int current_amount = new_amount;
	while (!pend.empty())
	{
		std::vector< std::pair<unsigned int, unsigned int> > newlist;
		while (current_amount > 0 && !pend.empty())
		{
			if (current_amount <= pend.size())
			{
				newlist.push_back(pend[current_amount - 1]);
				pend.erase(pend.begin() + current_amount - 1);
			}
			current_amount--;
		}
		super_pend.push_back(newlist);
		current_amount = prev_amount * 2 + new_amount;
		prev_amount = new_amount;
		new_amount = current_amount;
	}

	// std::cout << ">>> SUPER pend" << std::endl;
	// for (size_t i = 0; i < super_pend.size(); i++)
	// {
	// 	std::cout << "------- SIZE : " << super_pend[i].size() << std::endl;
	// 	for (size_t j = 0; j < super_pend[i].size(); j++)
	// 	{
	// 		std::cout << super_pend[i][j].first << "(paired with " << (super_pend[i][j].second) << ")" << std::endl;
	// 	}
	// }
	
	// insert elements from pend to main
	// use binary search to find the insertion position
	// search from 0 up to not including the element it was paired with
	// std::cout << ">>> INSERTION" << std::endl;
	while (!super_pend.empty())
	{
		while (!super_pend[0].empty())
		{
			unsigned int value = super_pend[0][0].first;
			unsigned int valuesPair = (super_pend[0][0].second);
			int lowerBound = 0;
			int upperBound = std::find(pair.second.begin(), pair.second.end(), valuesPair) - pair.second.begin();
			int insertIndex;
			// std::cout << "> inserting value : " << value << ", paired with " << valuesPair << " (index " << upperBound << ")" << std::endl;
			while (true)
			{
				_comp++;
				insertIndex = (upperBound + lowerBound) / 2;
				// std::cout << lowerBound << "(" << pair.second[lowerBound] << ") : " << insertIndex << "(" << pair.second[insertIndex] << ") : " << upperBound << "(" << pair.second[upperBound] << ")" << std::endl;
				if (lowerBound == upperBound || insertIndex == 0 || (value > pair.second[insertIndex-1] && value < pair.second[insertIndex]))
					break;
				if (value > pair.second[insertIndex])
				{
					if (lowerBound == (upperBound - 1))
						lowerBound = upperBound;
					else
						lowerBound = insertIndex;
				}
				else
				{
					if (lowerBound == (upperBound - 1))
						upperBound = lowerBound;
					upperBound = insertIndex;
				}
			}
			
			
			pair.second.insert(pair.second.begin() + insertIndex, value);
			super_pend[0].erase(super_pend[0].begin());
			// for (size_t i = 0; i < pair.second.size(); i++)
			// 	std::cout << pair.second[i] << std::endl;
		}
		super_pend.erase(super_pend.begin());
	}
	
	// THE STARGGLER
	if (straggler != _vector.end())
	{
		int lowerBound = 0;
		int upperBound = pair.second.size();
		int insertIndex;
		//std::cout << "> inserting value : " << *straggler << ", paired with *SOMETHING* (index " << upperBound << ")" << std::endl;
		while (true)
		{
			_comp++;
			insertIndex = (upperBound + lowerBound) / 2;
			// std::cout << lowerBound << "(" << pair.second[lowerBound] << ") : " << insertIndex << "(" << pair.second[insertIndex] << ") : " << upperBound << "(" << pair.second[upperBound] << ")" << std::endl;
			if ((*straggler > pair.second[insertIndex-1] && *straggler < pair.second[insertIndex]) || lowerBound == upperBound)
				break;
			if (*straggler > pair.second[insertIndex])
			{
				if (lowerBound == (upperBound - 1))
					lowerBound = upperBound;
				else
					lowerBound = insertIndex;
			}
			else
			{
				if (lowerBound == (upperBound - 1))
					upperBound = lowerBound;
				upperBound = insertIndex;
			}
		}
		pair.second.insert(pair.second.begin() + insertIndex, *straggler);
		// for (size_t i = 0; i < pair.second.size(); i++)
		// 	std::cout << pair.second[i] << std::endl;
	}

	
	std::cout << ">>> COMP : " << _comp << std::endl;
	std::cout << "time : " << (clock() - start ) / (double)CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
		
	return pair.second;
}

// std::deque<unsigned int> PmergeMe::sortDeque() 
// {
	
// 	return _deque;
// }

PmergeMe::PmergeMe() {}

PmergeMe::pairVector PmergeMe::mergeSortPairsVector(pairVector pair)
{
	if (pair.second.size() <= 1)
		return pair;
		
	pairVector p1;
	pairVector p2;

	for (size_t i = 0; i < pair.second.size() / 2; i++)
	{
		p1.first.push_back(pair.first[i]);
		p1.second.push_back(pair.second[i]);
	}
	for (size_t i = pair.second.size() / 2; i < pair.second.size(); i++)
	{
		p2.first.push_back(pair.first[i]);
		p2.second.push_back(pair.second[i]);
	}
	
	p1 = mergeSortPairsVector(p1);
	p2 = mergeSortPairsVector(p2);

	return mergeVectors(p1, p2);
}

PmergeMe::pairVector PmergeMe::mergeVectors(pairVector p1, pairVector p2)
{
	pairVector res;

	size_t i = 0;
	size_t j = 0;
	while (i < p1.second.size() && j < p2.second.size())
	{
		if (p1.second[i] > p2.second[j])
		{
			res.second.push_back(p2.second[j]);
			res.first.push_back(p2.first[j]);
			j++;
		}
		else
		{
			res.second.push_back(p1.second[i]);
			res.first.push_back(p1.first[i]);
			i++;
		}
		_comp++;
	}

	while (i < p1.second.size())
	{
		res.second.push_back(p1.second[i]);
		res.first.push_back(p1.first[i]);
		i++;
	}
	while (j < p2.second.size())
	{
		res.second.push_back(p2.second[j]);
		res.first.push_back(p2.first[j]);
		j++;
	}

	return res;
}
