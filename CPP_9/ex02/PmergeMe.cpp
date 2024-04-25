/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:44:26 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/24 19:48:34 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>
#include <iomanip>
/*--------------------------------Parsing---------------------------------*/
std::string combineArguments(char **av) {
	std::string combinedArgs;
	for (int i = 1; av[i] != NULL; ++i) {
		combinedArgs += av[i];
		combinedArgs += " ";
	}
	return combinedArgs;
}
/*-----------------------------------------------------------------------*/

PmergeMe::PmergeMe(void) {
	std::cout << "Not implemented\n";
}

PmergeMe::PmergeMe(char **av) : _timeVector(0), _timeDeque(0), _isOdd(false),  _additionalPrint(true) {
	if (av == NULL) {
		std::cerr << "Erreur : pointeur NULL passé en argument.\n";
		exit(1);
	}
	std::string combinedArgs = combineArguments(av);
	std::istringstream iss(combinedArgs);
	int value;
	while (iss >> value) {
		if (value < 0) {
			std::cerr << "Erreur : argument invalide '" << value << "'.\n";
			exit(1);
		}
		if (std::find(_vector.begin(), _vector.end(), value) == _vector.end()) {
			_vector.push_back(value);
		}
	}
	if (!iss.eof()) {
		std::cerr << "Erreur : argument invalide '" << iss.str() << "'.\n";
		exit(1);
	}
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it) {
		_deque.push_back(*it);
	}
	if (_vector.size() < 2) {
		std::cerr << "Erreur : pas assez d'élements a trier.\n";
		exit(1);
	}
	if (std::is_sorted(_vector.begin(), _vector.end())) {
		std::cout << "Les éléments sont déjà triés.\n";
		exit(0);
	}
	if (_vector.size() % 2 != 0) {
		_isOdd = true;
	}
	std::cout << "Before:  ";
	displaySequence(_vector);
	sortVector();
	sortDeque();
	std::cout << "After:   ";
	displaySequence(_vector);
	std::cout << "Time to process a range of " << std::setw(4) << _vector.size();
	std::cout << " elements with std::vector<int>: " << _timeVector.count() << "us" << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << _deque.size();
	std::cout << " elements with std::deque<int>: " << _timeDeque.count() << "us" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &other) {
	*this = other;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other) {
		_vector = other._vector;
		_vectorPairs = other._vectorPairs;
		_deque = other._deque;
		_dequePairs = other._dequePairs;
		_timeVector = other._timeVector;
		_timeDeque = other._timeDeque;
		_isOdd = other._isOdd;
		_oddNumber = other._oddNumber;
		_additionalPrint = other._additionalPrint;
	}
	return *this;
}

PmergeMe::~PmergeMe() {

}

bool compareSecond(const std::pair<int, int>& left, const std::pair<int, int>& right) {
	return left.second < right.second;
}
template<typename T>
void sortRecursive(T& pairs, typename T::iterator begin, typename T::iterator end) {
	if (begin == end || begin + 1 == end) {
		return;
	}

	typename T::iterator pivot = begin;
	typename T::iterator left = begin + 1;
	typename T::iterator right = end - 1;

	while (left <= right) {
		if (compareSecond(*left, *pivot)) {
			++left;
		} else if (!compareSecond(*right, *pivot)) {
			--right;
		} else {
			std::swap(*left, *right);
			++left;
			--right;
		}
	}

	std::swap(*pivot, *right);

	sortRecursive(pairs, begin, right);
	sortRecursive(pairs, right + 1, end);
}

template<typename T>
void sortBySecond(T& pairs) {
	sortRecursive(pairs, pairs.begin(), pairs.end());
}


void	PmergeMe::sortVector(){
	std::chrono::high_resolution_clock::time_point	start = std::chrono::high_resolution_clock::now();

	if(_isOdd) {
		_oddNumber = _vector.back();
		_vector.pop_back();
	}
	for(unsigned int i = 0; i < _vector.size(); i += 2) {
		_vectorPairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
	}
	_vector.clear();
	additionalPrint(PAIR);
	for (unsigned int i = 0; i < _vectorPairs.size(); i++) {
		if (_vectorPairs[i].first > _vectorPairs[i].second) {
			std::swap(_vectorPairs[i].first, _vectorPairs[i].second);
		}
	}
	additionalPrint(SORTPAIR);
	sortBySecond(_vectorPairs);
	additionalPrint(SORTPAIRS);
	for (std::vector<std::pair<int, int> >::iterator it = _vectorPairs.begin(); it != _vectorPairs.end(); it++) {
		_vector.push_back(it->second);
		it->second = -1;
	}
	additionalPrint(INSERTSECOND);
	std::vector<int>	jacobsthal_sequence = jacobsthalSequence<std::vector<int> >(_vectorPairs.size());
	if (_additionalPrint) {
		std::cout << "Jacobsthal sequence: ";
		displaySequence(jacobsthal_sequence);
	}
	_vector.insert(_vector.begin(), _vectorPairs.begin()->first);
	_vectorPairs.begin()->first = -1;
	for (unsigned int i = 0; i < jacobsthal_sequence.size(); i++)
	{
		int	to_add = _vectorPairs[jacobsthal_sequence[i] - 1].first;
		_vectorPairs[jacobsthal_sequence[i] - 1].first = -1;
		_vector.insert(std::lower_bound(_vector.begin(), _vector.end(), to_add), to_add);
	}
	if(_isOdd) {
		_vector.insert(std::lower_bound(_vector.begin(), _vector.end(), _oddNumber), _oddNumber);
	}
	additionalPrint(JACOBSTHAL);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	_timeVector = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

void	PmergeMe::sortDeque(){
	std::chrono::high_resolution_clock::time_point	start = std::chrono::high_resolution_clock::now();

	if(_isOdd) {
		_oddNumber = _deque.back();
		_deque.pop_back();
	}
	for(unsigned int i = 0; i < _deque.size(); i += 2) {
		_dequePairs.push_back(std::make_pair(_deque[i], _deque[i + 1]));
	}
	_deque.clear();
	for (unsigned int i = 0; i < _dequePairs.size(); i++) {
		if (_dequePairs[i].first > _dequePairs[i].second) {
			std::swap(_dequePairs[i].first, _dequePairs[i].second);
		}
	}
	sortBySecond(_dequePairs);
	for (std::deque<std::pair<int, int> >::iterator it = _dequePairs.begin(); it != _dequePairs.end(); it++) {
		_deque.push_back(it->second);
		it->second = -1;
	}
	std::deque<int>	jacobsthal_sequence = jacobsthalSequence<std::deque<int> >(_dequePairs.size());
	_deque.insert(_deque.begin(), _dequePairs.begin()->first);
	_dequePairs.begin()->first = -1;
	for (unsigned int i = 0; i < jacobsthal_sequence.size(); i++)
	{
		int	to_add = _dequePairs[jacobsthal_sequence[i] - 1].first;
		_dequePairs[jacobsthal_sequence[i] - 1].first = -1;
		_deque.insert(std::lower_bound(_deque.begin(), _deque.end(), to_add), to_add);
	}
	if(_isOdd) {
		_deque.insert(std::lower_bound(_deque.begin(), _deque.end(), _oddNumber), _oddNumber);
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	_timeDeque = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}


/*------------------------------------Display--------------------------------------*/
void PmergeMe::additionalPrint(Case cas) {
	if (!_additionalPrint) {
		return ;
	}
	std::cout << std::endl;
	switch (cas) {
		case PAIR:
			std::cout << "----Making pairs-----" << std::endl;
			break;
		case SORTPAIR:
			std::cout << "-----Sorting pair-----" << std::endl;
			break;
		case SORTPAIRS:
			std::cout << "-----Sorting pairs-----" << std::endl;
			break;
		case INSERTSECOND:
			std::cout << "-----Insert second-----" << std::endl;
			break;
		case JACOBSTHAL:
			std::cout << "-----Insert following jacobsthal order-----" << std::endl;
			break;
		default:
			break;
	}
	std::cout << "Vector Pairs:        ";
	displayPairs(_vectorPairs);
	std::cout << "Vector:              ";
	displaySequence(_vector);
	if (_isOdd && cas != JACOBSTHAL) {
		std::cout << "odd: " << _oddNumber << std::endl;
	} 
	std::cout << std::endl;
}

template<typename T>
static void	displaySequence(T seq) {
	for (size_t i = 0; i < seq.size(); ++i) {
		std::cout << seq[i] << " ";
	}
	std::cout << std::endl;
}
template<typename T>
static void	displayPairs(T seq) {
	for (size_t i = 0; i < seq.size(); ++i) {
		std::cout << "[";
		if (seq[i].first != -1) {
			std::cout << seq[i].first;
		} else {
			std::cout << " ";
		}
		std::cout << ", ";
		if (seq[i].second != -1) {
			std::cout << seq[i].second;
		} else {
			std::cout << " ";
		}
		std::cout << "] ";
	}
	std::cout << std::endl;
}
/*--------------------------------------------------------------------------------*/


static int		jacobsthal(int n) {
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return jacobsthal(n - 1) + (2 * jacobsthal(n - 2));
}

template<typename T>
T	PmergeMe::jacobsthalSequence(unsigned int seq_len) {
	T	sequence;
	unsigned int					index = 3;
	unsigned int					val;
	unsigned int					last = 1;

	while ((val = jacobsthal(index)) < seq_len - 1)
	{
		sequence.push_back(val);
		unsigned int	curr = val - 1;
		while (curr > last)
			sequence.push_back(curr--);
		index++;
		last = val;
	}
	if (sequence.empty() && seq_len != 1) {
		sequence.push_back(2);
	}
	if (sequence.size() != seq_len - 1)
	{
		unsigned int	max = *std::max_element(sequence.begin(), sequence.end());
		unsigned int	index = seq_len;
		while (index > max)
		{
			sequence.push_back(index);
			index--;
		}
	}
	return sequence;
}
