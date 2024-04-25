/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:34:21 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/25 15:41:21 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.h"

int main() {
	Data data;
	data.d = 42;
	data.lf = 3.14;

	std::cout << "Data.d: " << data.d << std::endl;
	std::cout << "Data.lf: " << data.lf << std::endl;
	uintptr_t serializedPtr = Serializer::serialize(&data);
	Data* deserializedPtr = Serializer::deserialize(serializedPtr);

	if (deserializedPtr == &data) {
		std::cout << "Serialization and deserialization successful." << std::endl;
		std::cout << "deserializedPtr->d: " << deserializedPtr->d << std::endl;
		std::cout << "deserializedPtr->lf: " << deserializedPtr->lf << std::endl;
	}
	else {
		std::cout << "Serialization and deserialization failed." << std::endl;
	}

	return 0;
}
