/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:48:25 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/26 16:31:22 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
typename T::iterator easyfind(T &container, int tofind) {
	typename T::iterator it = std::find(container.begin(), container.end(), tofind);
	return it;
	// if (it != container.end()) {
	// 	return it;
	// }
	// else {
	// 	throw std::runtime_error("Value not found in container.");
	// }
}
