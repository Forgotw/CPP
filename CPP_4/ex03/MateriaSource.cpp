/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:38:29 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/05 13:08:06 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Colors.h"


MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materiaList[i] = nullptr;
	}
	constructionMsg(MATERIASOURCE DEFCONS, MSGMODE);

}

MateriaSource::MateriaSource(MateriaSource const &other) {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] != nullptr) {
			_materiaList[i] = (other._materiaList[i])->clone();
		}
	}
	constructionMsg(MATERIASOURCE COPYCONS, MSGMODE);
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
	constructionMsg(MATERIASOURCE OPECONS, MSGMODE);
	return(*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] != nullptr){
			delete _materiaList[i];
		}
	}
	constructionMsg(MATERIASOURCE DEFDES, MSGMODE);
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_materiaList[i] == nullptr) {
			this->_materiaList[i] = m;
			std::cout << MATERIASOURCE << BOLD GREEN << m->getType() << " " << RESET << EQUIPED CYAN << i << RESET << std::endl; 
			return ;
		}
	}
	std::cout << MATERIASOURCE INVENTORYFULL << std::endl;
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] != nullptr && _materiaList[i]->getType() == type ) {
			return (_materiaList[i]->clone());
		}
	}
	return 0;
}
