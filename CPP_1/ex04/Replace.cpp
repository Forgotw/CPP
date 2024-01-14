/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:45:28 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/14 15:41:59 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(void) {
}

Replace::~Replace(void) {
}

bool	Replace::checkArguments(std::string fileName, std::string toFind, std::string toReplace) {
	if (fileName.empty() || toFind.empty() || toReplace.empty()) {
		std::cerr << "Error: Empty string detected" << std::endl;
		return false;
	}
	return true;
}

bool	Replace::checkInputFile(std::ifstream& file, std::string fileName) {
	if (file.is_open() && file.good())
		return true;
	else {
		file.close();
		std::cerr << "Error: Opening file " << fileName << std::endl;
		return false;
	}
}

bool	Replace::newOutputFile(std::string fileName, std::string fileContent) {
	std::string newFileName = fileName + ".replace";
	std::ofstream newFile(newFileName.c_str());
	if (!newFile.is_open() || !newFile.good()) {
		std::cerr << "Error: Cannot create new file: " << fileName << std::endl;
		newFile.close();
		return false;
	}
	newFile << fileContent;
	newFile.close();
	return true;
}

std::string	Replace::doReplace(std::ifstream& originalFile, std::string toFind, std::string toReplace) {
	std::stringstream	buffer;
	buffer << originalFile.rdbuf();
	std::string	fileContent = buffer.str();
	size_t	pos = 0;
	size_t	i = 0;
	while ((pos = fileContent.find(toFind, pos)) != std::string::npos) {
		fileContent = fileContent.substr(0, pos) + toReplace + fileContent.substr(pos + toFind.length());
		pos += toReplace.length();
		i++;
	}
	std::cout << "Found " << i << " occurences of " << toFind << std::endl;
	return fileContent;
}

void	Replace::replaceInNewFile(std::string fileName, std::string toFind, std::string toReplace) {
	if (checkArguments(fileName, toFind, toReplace) == false)
		return ;
	std::ifstream originalFile(fileName.c_str());
	if (checkInputFile(originalFile, fileName) == false)
		return ;
	std::string fileContent = doReplace(originalFile, toFind, toReplace);
	if (newOutputFile(fileName, fileContent) == false)
		return ;
	originalFile.close();
}
