/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:38:29 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/02 15:12:17 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Colors.h"


MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materiaList[i] = nullptr;
	}
	std::cout << MATERIASOURCE DEFCONS << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] != nullptr) {
			_materiaList[i] = (other._materiaList[i])->clone();
		}
	}
	std::cout << MATERIASOURCE COPYCONS << std::endl;
}


MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_materiaList[i] != nullptr){
				delete _materiaList[i];
				_materiaList[i] = (other._materiaList[i])->clone();
			}
		}
	}
	std::cout << MATERIASOURCE OPECONS << std::endl;
	return(*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] != nullptr){
			delete _materiaList[i];
		}
	}
	std::cout << MATERIASOURCE DEFDES << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_materiaList[i] == nullptr) {
			this->_materiaList[i] = m->clone();
			std::cout << EQUIPED CYAN << i << RESET << std::endl; 
			return ;
		}
	}
	std::cout << "Source: " INVENTORYFULL << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] != nullptr && _materiaList[i]->getType() == type ) {
			return (_materiaList[i]->clone());
		}
	}
	return 0;
}
