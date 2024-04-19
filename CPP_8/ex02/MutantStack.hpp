/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:37:44 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/19 14:14:34 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack() {};
		MutantStack(MutantStack const &other) {
			*this = other;
		};

		~MutantStack() {};
		MutantStack	&operator=(MutantStack const &other) {
			if (this != &other) {
				*this = other;
			}
			return *this;
		};
		typedef typename	std::stack<T>::container_type::iterator iterator;
		iterator	begin(void) {
			return this->c.begin();
		};
		iterator	end(void) {
			return this->c.end();
		};

		typedef typename	std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin(void) const {
			return this->c.begin();
		};
		const_iterator	end(void) const {
			return this->c.end();
		};
};


