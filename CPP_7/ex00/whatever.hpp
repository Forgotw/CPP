/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:12:19 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/27 15:08:36 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min(T a, T b) {
	return (a < b) ? a : b;
}

template<typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}
