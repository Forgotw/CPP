/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:41:31 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/24 17:41:40 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

enum Case {
	PAIR,
	SORTPAIR,
	SORTPAIRS,
	INSERTSECOND,
	JACOBSTHAL
};
class PmergeMe {
	private:
		std::vector<int>					_vector;
		std::vector<std::pair<int ,int> >	_vectorPairs;
		std::deque<int>						_deque;
		std::deque<std::pair<int ,int> >	_dequePairs;
		std::chrono::microseconds			_timeVector;
		std::chrono::microseconds			_timeDeque;
		bool				_isOdd;
		int					_oddNumber;
		bool				_additionalPrint;
	public:
		PmergeMe(char **av);
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe	&operator=(PmergeMe const &other);

		void	sortVector();
		void	sortDeque();

		void	additionalPrint(Case cas);
		template<typename T>
		T		jacobsthalSequence(unsigned int seq_len);
		

};
template<typename T>
static void	displaySequence(T seq);
template<typename T>
static void	displayPairs(T seq);
