/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:39:46 by lsohler           #+#    #+#             */
/*   Updated: 2024/04/19 13:56:41 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>



int main() {
    // Création d'une instance de Span
    Span span(200);

    // Ajout de nombres aléatoires
    std::srand(std::time(nullptr));
    try {
		for (int i = 0; i < 200; ++i) {
			span.addNumber(std::rand() % 200);
		}
		span.printSpan();
	} catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    // Calcul de la plus petite et de la plus grande différence
    try {
        unsigned int shortest = span.shortestSpan();
        unsigned int longest = span.longestSpan();

        std::cout << "Shortest span: " << shortest << std::endl;
        std::cout << "Longest span: " << longest << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test pour vérifier le lancement de l'exception pour le cas où il y a moins de deux nombres
    Span smallSpan(2);
    smallSpan.addNumber(42);
	smallSpan.printSpan();
    try {
        unsigned int shortest = smallSpan.shortestSpan();
        unsigned int longest = smallSpan.longestSpan();

        std::cout << "Shortest span: " << shortest << std::endl;
        std::cout << "Longest span: " << longest << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
	try {
		smallSpan.addNumber(4);
		smallSpan.addNumber(5);
	} catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

	Span spanRange(10, 57);
	spanRange.printSpan();
    try {
        unsigned int shortest = spanRange.shortestSpan();
        unsigned int longest = spanRange.longestSpan();

        std::cout << "Shortest span2: " << shortest << std::endl;
        std::cout << "Longest span2: " << longest << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
    return 0;
}
