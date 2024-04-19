/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:21:34 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/26 13:59:30 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template<typename T>

class Array {

	private:
		T*				_array;
		unsigned int	_size;

	public:
		
		Array(void) : _array(nullptr), _size(0) {}

		Array(unsigned int n) : _array(new T[n]), _size(n) {
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = T();
			}
		}

		Array(const Array &other) : _array(new T[other.size()]), _size(other.size()) {
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = other._array[i];
			}
		}

		~Array() {
			delete[] _array;
		}

		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _array;
				_size = other.size();
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					_array[i] = other._array[i];
				}
			}
			return *this;
		}

		T& operator[](unsigned int index) {
		if (index >= _size) {
			throw std::out_of_range("Index out of bounds");
			}
		return _array[index];
		}

		unsigned int  size( void ) const { 
			return _size;
		}
};
