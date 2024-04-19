/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:37:44 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/19 13:48:11 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
# include <iostream>
# include <string>
# include <set>
# include <list>
# include <vector>
# include <algorithm>
# include <exception>
# include <vector>

class Span
{
	private:
		std::set<int>	_container;
		unsigned int	_size;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span(int start, int end);

		~Span();

		Span &operator=(Span const &other);
		void			addNumber(int number);
		void			addNumbers(std::set<int>::iterator first, std::set<int>::iterator last);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			printSpan(void);
};

std::set<int> createSetRange(int start, int end);
