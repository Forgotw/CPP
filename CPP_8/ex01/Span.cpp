/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:37:46 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/19 13:54:13 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _size(0) {

}

Span::Span(unsigned int n) : _size(n) {

}

Span::Span(Span const &other) : _container(other._container), _size(other._size) {

}

Span::~Span() {

}

Span::Span(int start, int end) {
	if (start <= end) {
		for (int i = start; i <= end; ++i) {
			_container.insert(i);
			_size++;
		}
	}
	else {
		for (int i = start; i >= end; --i) {
			_container.insert(i);
			_size++;
		}
	}
}

Span &Span::operator=(Span const &other) {
	if (this != &other) {
		_container = other._container;
		_size = other._size;
	}
	return(*this);
}

void	Span::addNumber(int number) {
	if (_container.size() >= _size) {
		throw std::length_error("Maximum size reached");
	}
	_container.insert(number);
}

void	Span::addNumbers(std::set<int>::iterator first, std::set<int>::iterator last) {
	while (first != last) {
		this->addNumber(*first);
		++first;
	}
}

unsigned int	Span::shortestSpan(void) {
	int						min = INT_MAX;
	std::set<int>::iterator current = _container.begin();
	std::set<int>::iterator next = current;

	while (++next != _container.end()) {
		if (*next - *current < min)
			min = *next - *current++;
	}
	return min;
}

unsigned int	Span::longestSpan(void) {
	if (_container.size() < 2)
		throw std::length_error("Lenght Error");
	return (*--(_container.end()) - *_container.begin());
}

void Span::printSpan() {
    std::cout << "Span content: ";
    for (std::set<int>::iterator it = _container.begin(); it != _container.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != _container.end()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}
