/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:08:35 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/09 15:38:01 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

#include <string>
#include <iostream>

#define RESET          "\033[0m"
#define BOLD           "\033[1m"
#define UNDERLINE      "\033[4m"
#define BLINK          "\033[5m"
#define REVERSE        "\033[7m"
#define CONCEALED      "\033[8m"

// Text colors
#define BLACK          "\033[30m"
#define RED            "\033[31m"
#define GREEN          "\033[32m"
#define YELLOW         "\033[33m"
#define BLUE           "\033[34m"
#define MAGENTA        "\033[35m"
#define CYAN           "\033[36m"
#define WHITE          "\033[37m"

// Background colors
#define BGBLACK        "\033[40m"
#define BGRED          "\033[41m"
#define BGGREEN        "\033[42m"
#define BGYELLOW       "\033[43m"
#define BGBLUE         "\033[44m"
#define BGMAGENTA      "\033[45m"
#define BGCYAN         "\033[46m"
#define BGWHITE        "\033[47m"

// Bright text colors
#define BRIGHTBLACK    "\033[90m"
#define BRIGHTRED      "\033[91m"
#define BRIGHTGREEN    "\033[92m"
#define BRIGHTYELLOW   "\033[93m"
#define BRIGHTBLUE     "\033[94m"
#define BRIGHTMAGENTA  "\033[95m"
#define BRIGHTCYAN     "\033[96m"
#define BRIGHTWHITE    "\033[97m"

// Bright background colors
#define BGBRIGHTBLACK  "\033[100m"
#define BGBRIGHTRED    "\033[101m"
#define BGBRIGHTGREEN  "\033[102m"
#define BGBRIGHTYELLOW "\033[103m"
#define BGBRIGHTBLUE   "\033[104m"
#define BGBRIGHTMAGENTA "\033[105m"
#define BGBRIGHTCYAN   "\033[106m"
#define BGBRIGHTWHITE  "\033[107m"

#define MSGMODE 1

#define DEFCONS GREEN  "Default Constructor called." RESET
#define COPYCONS CYAN "Copy Constructor called." RESET
#define OPECONS MAGENTA "Operator Constructor called." RESET
#define DEFDES RED "Default Destructor called." RESET

#define BUREAUCRAT BOLD WHITE "Bureaucrat: " RESET


void	constructionMsg(std::string msg, int mode);
void	endline(int	n);
void	printSeparator(std::string str, std::string color);

#endif
