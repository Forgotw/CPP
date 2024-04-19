/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:37:50 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/26 16:37:52 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <array>
#include <algorithm>
#include <stdexcept>
#include "easyfind.hpp"

#define MAX_VAL 15

int main() {
	// Test avec un vecteur
	int searching = 0;
	std::cout << "Testing with vector:" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < MAX_VAL; i++)
		vec.push_back(i);
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << "vec[" << i << "]: " << vec[i] << " ";
	std::cout << std::endl;
	searching = 3;
	std::vector<int>::iterator result_vec = easyfind(vec, searching);
	std::cout << "Searching: " << searching << std::endl;
	std::cout << "easyfind: " << *result_vec << std::endl;
	if (result_vec != vec.end()) {
		std::cout << "   Value: found at index: " << std::distance(vec.begin(), result_vec) << std::endl;
	}
	else {
		std::cout << "   Value not found in the vector." << std::endl;
	}

	// Test avec une liste
	std::cout << "\nTesting with list:" << std::endl;
	std::list<int> lst;
	for (int i = 0; i < MAX_VAL; i++)
		lst.push_back(i);
	std::cout << "Contents of list: ";
	std::list<int>::iterator it;
	for (it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	searching = 30;
	std::list<int>::iterator result_lst = easyfind(lst, searching);
	std::cout << "Searching: " << searching << std::endl;
	std::cout << "easyfind: " << *result_lst << std::endl;
	if (result_lst != lst.end()) {
		std::cout << "   Value found" << std::endl;
	}
	else {
		std::cout << "   Value not found in the list." << std::endl;
	}

	// Test avec un ensemble
	std::cout << "\nTesting with set:" << std::endl;
	std::set<int> st;
	for (int i = 0; i < MAX_VAL; i++)
		st.insert(i);
	std::cout << "Contents of set: ";
	std::set<int>::iterator it2;
	for (it2 = st.begin(); it2 != st.end(); ++it2) {
		std::cout << *it2 << " ";
	}
	std::cout << std::endl;
	searching = 15;
	std::set<int>::iterator result_set = easyfind(st, searching);
	std::cout << "Searching: " << searching << std::endl;
	std::cout << "easyfind: " << *result_set << std::endl;
	if (result_set != st.end()) {
		std::cout << "   Value found" << std::endl;
	}
	else {
		std::cout << "   Value not found in the set." << std::endl;
	}

	// Test avec un tableau
	std::cout << "\nTesting with array:" << std::endl;
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		std::cout << "arr[" << i << "]: " << arr[i];
	std::cout << std::endl;
	searching = 5;
	std::array<int, 5>::iterator result_arr = easyfind(arr, searching);
	std::cout << "Searching: " << searching << std::endl;
	std::cout << "easyfind: " << *result_arr << std::endl;
	if (result_arr != arr.end()) {
		std::cout << "   Value found at index: " << std::distance(arr.begin(), result_arr) << std::endl;
	}
	else {
		std::cout << "   Value not found in the array." << std::endl;
	}

	return 0;
}
