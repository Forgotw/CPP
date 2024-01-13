/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:45:28 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/13 17:40:50 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(void) {
}

Replace::~Replace(void) {
}

void	Replace::enterParam(std::string filename, std::string tofind, std::string toReplace) {
	this->_Filename = filename;
	this->_toFind = tofind;
	this->_toReplace = toReplace;
}

bool	Replace::checkInputFile(std::ifstream file) {
	if (file.is_open() && file.good())
		return true;
	else {
		file.close();
		return false;
	}
}

void	Replace::newOutputFile(std::ofstream newFile, std::string fileContent) {
	std::string newFileName = _Filename + ".replace";
	std::ofstream newFile(newFileName.c_str());
	if (!newFile.is_open() || !newFile.good()) {
		std::cout << "Cannot create new file" << std::endl;
	}
}

void	Replace::doReplace() {
	std::ifstream	originalFile.open(_Filename.c_str());
	if (checkInputFile(originalFile) == false)
		return ;
	std::stringstream	buffer;
	buffer << originalFile.rdbuf();
	std::string	fileContent = buffer.str();
	size_t pos = 0;
	while ((pos = fileContent.find(_toFind, pos)) != std::string::npos) {
		fileContent = fileContent.substr(0, pos) + _toReplace + fileContent.substr(pos, + _toFind.length());
		pos += _toReplace.length();
	}


}