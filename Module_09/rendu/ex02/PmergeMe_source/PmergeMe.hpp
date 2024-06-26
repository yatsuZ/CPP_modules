/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/26 01:33:24 by yzaoui           ###   ########.fr       */
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
#include <ctime>


#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"



class PmergeMe
{
private:
	std::vector<int>	_VectorTrie;
	std::list<int>		_ListTrie;
	int	_nbrOfElement;

	std::vector<int>		_sortVector(std::vector<int>::iterator First , std::vector<int>::iterator Last, size_t len);
	std::list<int>		_sortList(std::list<int>::iterator First , std::list<int>::iterator Last, size_t len);


	double	_sortVectorTime(void);
	double	_sortListTime(void);

	int	_strToInt(std::string) const;
	
	bool	_isSorted(bool show);
	void	_showContenair(size_t len) const;

	PmergeMe(void);
public:
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();

	void exec(bool);
};

#endif