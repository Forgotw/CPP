#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "Materia.hpp"

class IMateriaSource {
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource {
	private:
		AMateria*	_materiaList[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &other);

		void		learnMateria(AMateria* other);
		AMateria*	createMateria(std::string const & type);
};
