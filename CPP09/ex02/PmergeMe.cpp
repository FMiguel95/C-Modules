/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:12:15 by fernacar          #+#    #+#             */
/*   Updated: 2024/05/08 20:24:12 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char**av)
{
	std::cout << "Before:\t";
	for (int i = 1; i < ac; i++)
	{
		int number = std::atoi(av[i]);
		std::cout << number << " ";
		_vector.push_back(number);
		_deque.push_back(number);
	}
	std::cout << std::endl;

	clock_t startVector = clock();
	std::vector<unsigned int> vec = sortVector();
	double endTimeVector = (clock() - startVector ) / (double)CLOCKS_PER_SEC * 1000;

	clock_t startDeque = clock();
	std::deque<unsigned int> deq = sortDeque();
	double endTimeDeque = (clock() - startDeque ) / (double)CLOCKS_PER_SEC * 1000;

	std::cout << "After:\t";
	for (std::vector<unsigned int>::iterator i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << endTimeVector << " ms" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << endTimeDeque << " ms" << std::endl;
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

PmergeMe::PmergeMe() {}

std::vector<unsigned int> PmergeMe::sortVector()
{
	if (_vector.size() <= 1)
		return _vector;
	// save and remove last element if odd number
	std::vector<unsigned int>::const_iterator straggler;
	if (_vector.size() % 2)
		straggler = _vector.end() - 1;
	else
		straggler = _vector.end();

	// create list of pairs
	pairVector pair;
	std::vector<unsigned int>& pend = pair.first;
	std::vector<unsigned int>& main = pair.second;
	for (size_t i = 0; i < _vector.size() / 2; i++)
	{
		pend.push_back(_vector[i * 2]);
		main.push_back(_vector[i * 2 + 1]);
	}
		
	// for each pair compare elements and sort them
	for (size_t i = 0; i < _vector.size() / 2; i++)
	{
		if (pend[i] > main[i])
			std::swap(pend[i], main[i]);
	}
	
	// recursively sort pairs based on largest element
	pair = mergeSortPairsVector(pair);

	// move smallest member of pend to the start of main
	main.insert(main.begin(), pend.front());
	pend.erase(pend.begin());

	// order pend for best insertion sequence
	//// create list of pend numbers and their main pair
	std::vector< std::pair<unsigned int, unsigned int> > pendPair;
	for (size_t i = 0; i < pend.size(); i++)
	{
		std::pair<unsigned int, unsigned int> temp;
		temp.first = pend[i];
		temp.second = main[i + 2];
		pendPair.push_back(temp);
	}
	//// create list of lists of pairs of numbers/numbers 😩 and fill it with the best insertion order
	std::vector<std::vector< std::pair<unsigned int, unsigned int> > > pendJacobsthal;
	unsigned int prev_amount = 0;
	unsigned int new_amount = 2;
	unsigned int current_amount = new_amount;
	while (!pendPair.empty())
	{
		std::vector< std::pair<unsigned int, unsigned int> > newlist;
		while (current_amount > 0 && !pendPair.empty())
		{
			if (current_amount <= pendPair.size())
			{
				newlist.push_back(pendPair[current_amount - 1]);
				pendPair.erase(pendPair.begin() + current_amount - 1);
			}
			current_amount--;
		}
		pendJacobsthal.push_back(newlist);
		current_amount = prev_amount * 2 + new_amount;
		prev_amount = new_amount;
		new_amount = current_amount;
	}

	// insert elements from pend to main
	// use binary search to find the insertion position
	// search from 0 up to not including the element it was paired with
	while (!pendJacobsthal.empty())
	{
		while (!pendJacobsthal.front().empty())
		{
			unsigned int value = pendJacobsthal.front().front().first;
			int lowerBound = 0;
			int upperBound = std::find(main.begin(), main.end(), pendJacobsthal.front().front().second) - main.begin();	// index of the number the value was paired with
			int insertIndex;
			while (true)
			{
				insertIndex = (upperBound + lowerBound) / 2;
				if (lowerBound == upperBound || insertIndex == 0 || (value > main[insertIndex-1] && value < main[insertIndex]))
					break;
				if (value > main[insertIndex])
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
					else
						upperBound = insertIndex;
				}
			}
			main.insert(main.begin() + insertIndex, value);
			pendJacobsthal.front().erase(pendJacobsthal.front().begin());
		}
		pendJacobsthal.erase(pendJacobsthal.begin());
	}

	// likewise insert the straggler if it exists
	if (straggler != _vector.end())
	{
		int lowerBound = 0;
		int upperBound = main.size();
		int insertIndex;
		while (true)
		{
			insertIndex = (upperBound + lowerBound) / 2;
			if (lowerBound == upperBound || insertIndex == 0 || (*straggler > main[insertIndex-1] && *straggler < main[insertIndex]))
				break;
			if (*straggler > main[insertIndex])
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
				else
					upperBound = insertIndex;
			}
		}
		main.insert(main.begin() + insertIndex, *straggler);
	}

	return main;
}

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

std::deque<unsigned int> PmergeMe::sortDeque()
{
	if (_deque.size() <= 1)
		return _deque;
	// save and remove last element if odd number
	std::deque<unsigned int>::const_iterator straggler;
	if (_deque.size() % 2)
		straggler = _deque.end() - 1;
	else
		straggler = _deque.end();

	// create list of pairs
	pairDeque pair;
	std::deque<unsigned int>& pend = pair.first;
	std::deque<unsigned int>& main = pair.second;
	for (size_t i = 0; i < _deque.size() / 2; i++)
	{
		pend.push_back(_deque[i * 2]);
		main.push_back(_deque[i * 2 + 1]);
	}

	// for each pair compare elements and sort them
	for (size_t i = 0; i < _deque.size() / 2; i++)
	{
		if (pend[i] > main[i])
			std::swap(pend[i], main[i]);
	}

	// recursively sort pairs based on largest element
	pair = mergeSortPairsDeque(pair);

	// move smallest member of pend to the start of main
	main.push_front(pend.front());
	pend.pop_front();

	// order pend for best insertion sequence
	//// create list of pend numbers and their main pair
	std::deque< std::pair<unsigned int, unsigned int> > pendPair;
	for (size_t i = 0; i < pend.size(); i++)
	{
		std::pair<unsigned int, unsigned int> temp;
		temp.first = pend[i];
		temp.second = main[i + 2];
		pendPair.push_back(temp);
	}
	//// create list of lists of pairs of numbers/numbers 😩 and fill it with the best insertion order
	std::deque<std::deque< std::pair<unsigned int, unsigned int> > > pendJacobsthal;
	unsigned int prev_amount = 0;
	unsigned int new_amount = 2;
	unsigned int current_amount = new_amount;
	while (!pendPair.empty())
	{
		std::deque< std::pair<unsigned int, unsigned int> > newlist;
		while (current_amount > 0 && !pendPair.empty())
		{
			if (current_amount <= pendPair.size())
			{
				newlist.push_back(pendPair[current_amount - 1]);
				pendPair.erase(pendPair.begin() + current_amount - 1);
			}
			current_amount--;
		}
		pendJacobsthal.push_back(newlist);
		current_amount = prev_amount * 2 + new_amount;
		prev_amount = new_amount;
		new_amount = current_amount;
	}

	// insert elements from pend to main
	// use binary search to find the insertion position
	// search from 0 up to not including the element it was paired with
	while (!pendJacobsthal.empty())
	{
		while (!pendJacobsthal.front().empty())
		{
			unsigned int value = pendJacobsthal.front().front().first;
			int lowerBound = 0;
			int upperBound = std::find(main.begin(), main.end(), pendJacobsthal.front().front().second) - main.begin();	// index of the number the value was paired with
			int insertIndex;
			while (true)
			{
				insertIndex = (upperBound + lowerBound) / 2;
				if (lowerBound == upperBound || insertIndex == 0 || (value > main[insertIndex-1] && value < main[insertIndex]))
					break;
				if (value > main[insertIndex])
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
					else
						upperBound = insertIndex;
				}
			}
			main.insert(main.begin() + insertIndex, value);
			pendJacobsthal.front().pop_front();
		}
		pendJacobsthal.erase(pendJacobsthal.begin());
	}

	// likewise insert the straggler if it exists
	if (straggler != _deque.end())
	{
		int lowerBound = 0;
		int upperBound = main.size();
		int insertIndex;
		while (true)
		{
			insertIndex = (upperBound + lowerBound) / 2;
			if (lowerBound == upperBound || insertIndex == 0 || (*straggler > main[insertIndex-1] && *straggler < main[insertIndex]))
				break;
			if (*straggler > main[insertIndex])
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
				else
					upperBound = insertIndex;
			}
		}
		main.insert(main.begin() + insertIndex, *straggler);
	}

	return main;
}

PmergeMe::pairDeque PmergeMe::mergeSortPairsDeque(pairDeque pair)
{
	if (pair.second.size() <= 1)
		return pair;

	pairDeque p1;
	pairDeque p2;

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

	p1 = mergeSortPairsDeque(p1);
	p2 = mergeSortPairsDeque(p2);

	return mergeDeques(p1, p2);
}

PmergeMe::pairDeque PmergeMe::mergeDeques(pairDeque p1, pairDeque p2)
{
	pairDeque res;

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
