/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:53:01 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/25 16:01:21 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
public:
	virtual ~Base() {};
};	

class A : public Base {};
class B : public Base {};
class C : public Base {};
class D : public Base {};

Base* generate() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int randomNum = std::rand() % 4;

	switch (randomNum) {
		case 0:
			std::cout << "Generate Class: A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generate Class: B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generate Class: C" << std::endl;
			return new C();
		case 3:
			std::cout << "Generate Class: D" << std::endl;
			return new D();
	}
	return nullptr;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
	else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	if (dynamic_cast<A*>(&p)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(&p)) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(&p)) {
		std::cout << "C" << std::endl;
	}
	else {
		std::cout << "Unknown type" << std::endl;
	}
}

int main() {
	Base* obj = generate();

	std::cout << "Identifying using pointer: ";
	identify(obj);
	std::cout << "Identifying using reference: ";
	identify(*obj);

	delete obj;
	return 0;
}
