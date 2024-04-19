/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:23:24 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/25 16:23:41 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iter.hpp"

int main() {
	// Test with an array of integers
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Iterating over intArray: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	// Test with an array of doubles
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::cout << "Iterating over doubleArray: ";
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;

	// Test with an array of strings
	std::string stringArray[] = {"apple", "banana", "cherry"};
	std::cout << "Iterating over stringArray: ";
	iter(stringArray, 3, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}
