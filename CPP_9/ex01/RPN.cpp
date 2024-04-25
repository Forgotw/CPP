/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:49:42 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/19 15:33:15 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	
}

static const std::string ops = "+-*/";

static bool	isOp(char c) {
	return ops.find(c) != std::string::npos;
}

static bool applyOp(char c, std::stack<int> &stack) {
	if (stack.size() < 2) {
		std::cout << "Error: not enough Operand\n";
		return false;
	}
	int	second = stack.top();
	stack.pop();
	int	first = stack.top();
	stack.pop();
	switch (c) {
		case '*':
			stack.push(first * second);
			break;
		case '+':
			stack.push(first + second);
			break;
		case '-':
			stack.push(first - second);
			break;
		case '/':
			if (second != 0) {
				stack.push(first / second);
			} else {
				std::cout << "Error: Cannont divide by 0.\n";
			}
			break;
		default:
			break;
	}
	return true;
}

void	RPN::calc(std::string str) {
	std::stack<int>		stack;

	for (unsigned int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (isOp(c) || isdigit(c) || c == ' ') {
			if (isOp(c) && !applyOp(c, stack)) {
				return ;
			} else if (isdigit(c)) {
				stack.push(c - '0');
			}
		} else {
			std::cout << "Error: invalid char.\n";
			return ;
		}
	}
	if (stack.size() == 1) {
		std::cout << "Result = " << stack.top() << std::endl;
	} else {
		std::cout << "Error: invalid notation.\n";
		return ;
	}
}
