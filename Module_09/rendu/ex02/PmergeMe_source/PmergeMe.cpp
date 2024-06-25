/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/25 19:44:20 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

PmergeMe::PmergeMe(void):
_VectorTrie(std::vector<int>()),
_ListTrie(std::list<int>()),
_nbrOfElement(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &src):
_VectorTrie(src._VectorTrie),
_ListTrie(src._ListTrie)
{
}

PmergeMe::~PmergeMe()
{
}

////////////////////////////////////////////////////////

int	PmergeMe::_strToInt(std::string str) const
{
	if (str.empty())
		throw std::invalid_argument("In the input there is an argument which is not a positive integer");

	char *end;
	errno = 0;
	
	long result = std::strtol(str.c_str(), &end, 10);
	if (errno == ERANGE || *end || result < 0 || result > std::numeric_limits<int>().max())
		throw std::invalid_argument("In the input there is an argument which is not a positive integer.");
	return static_cast<int>(result);
}

PmergeMe::PmergeMe(int argc, char **argv):
_VectorTrie(std::vector<int>()),
_ListTrie(std::list<int>()),
_nbrOfElement(argc - 1)
{
	for (int i = 1; i < argc; i++)
	{
		int res = this->_strToInt(argv[i]);
		this->_VectorTrie.push_back(res);
		this->_ListTrie.push_back(res);
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_VectorTrie = src._VectorTrie;
		this->_ListTrie = src._ListTrie;
	}
	return (*this);
}

////////

void	PmergeMe::_showContenair(size_t len) const
{
	if (this->_ListTrie.empty())
	{
		std::cout << "EMPTY" << std::endl;
		return ;
	}
	if (!len)
		len = this->_ListTrie.size();
	std::list<int>::const_iterator i = this->_ListTrie.begin();
	for (; i != this->_ListTrie.end() && len; i++, len--)
	{
		std::cout << *i << " ";
	}
	if (i != this->_ListTrie.end())
		std::cout << "[...]";
	std::cout << std::endl;
}

void PmergeMe::exec(void)
{
	std::cout << "Before:\t";
	this->_showContenair(5);
	std::cout << "nbr of element : " << this->_nbrOfElement << std::endl;
//Faire les 2 trie ici
	// std::cout << "After:\t";
	// this->_showContenair(5);
	// std::cout << "Time to process a range of " << this->_nbrOfElement << " elements with std::list<int>\t:" << timeList << " us" << std::endl;
	// std::cout << "Time to process a range of " << this->_nbrOfElement << " elements with std::vector<int>\t:" << timeVector << " us" << std::endl;
}