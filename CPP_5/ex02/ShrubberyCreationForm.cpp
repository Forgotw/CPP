/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:42:45 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/15 12:39:47 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {
	constructionMsg(SHRUBBERYCREATIONFORM DEFCONS, MSGMODE);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	constructionMsg(SHRUBBERYCREATIONFORM DEFCONS, MSGMODE);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target) {
	constructionMsg(SHRUBBERYCREATIONFORM COPYCONS, MSGMODE);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	constructionMsg(SHRUBBERYCREATIONFORM DEFDES, MSGMODE);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	constructionMsg(SHRUBBERYCREATIONFORM OPECONS, MSGMODE);
	if (this != &other) {
		*this = ShrubberyCreationForm(other);
	}
	return(*this);
}

void	ShrubberyCreationForm::executeConcrete(void) const {
	std::ofstream file(_target + "_shrubbery");	
	file << "          .     .  .      +     .      .          ." << std::endl;
	file << "     .       .      .     #       .           ." << std::endl;
	file << "        .      .         ###            .      .      ." << std::endl;
	file << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
	file << "          .      . \"####\"###\"####\"  ." << std::endl;
	file << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
	file << "  .             \"#########\"#########\"        .        ." << std::endl;
	file << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
	file << "     .     .  \"#######\"##\"####\"##\"#######\"                  ." << std::endl;
	file << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
	file << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
	file << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
	file << "        .     \"      000      \"    .     ." << std::endl;
	file << "       .         .   .   000     .        .       ." << std::endl;
	file << ".. .. ..................O000O........................ ...... " << std::endl;
}
