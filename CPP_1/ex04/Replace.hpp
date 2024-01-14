/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:44:22 by lsohler           #+#    #+#             */
/*   Updated: 2024/01/14 15:40:15 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Replace {
/*
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.
*/
public:

	Replace(void);
	~Replace(void);
	void	replaceInNewFile(std::string fileName, std::string toFind, std::string toReplace);

private:

	std::string	doReplace(std::ifstream& originalFile, std::string toFind, std::string toReplace);
	bool	newOutputFile(std::string filename, std::string fileContent);
	bool	checkInputFile(std::ifstream& file, std::string filename);
	bool	checkArguments(std::string fileName, std::string toFind, std::string toReplace);


};


#endif
