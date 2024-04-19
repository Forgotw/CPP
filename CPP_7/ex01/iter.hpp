/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:21:41 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/25 16:33:57 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>

template<typename T, typename F>
void iter(T* array, size_t length, F function) {
	// std::cout << std::endl;
	for (size_t i = 0; i < length; ++i) {
		// usleep(400000);
		function(array[i]);
	}
}

template<typename T>
void printElement(const T& element) {
	std::cout << element << " ";// << std::endl;
}
