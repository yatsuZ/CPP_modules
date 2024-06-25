/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/25 19:40:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <list>
#include <vector>

class PmergeMe
{
private:
	std::vector<int>	_VectorTrie;
	std::list<int>		_ListTrie;
	int	_nbrOfElement;

	int	_strToInt(std::string) const;
	
	void	_showContenair(size_t len) const;

	PmergeMe(void);
public:
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();

	void exec(void);
};

#endif