/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/26 02:15:44 by yzaoui           ###   ########.fr       */
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
	if (!this->_nbrOfElement)
		throw std::invalid_argument("Needs argument positive integer.");
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

bool	PmergeMe::_isSorted(bool show)
{
	bool	listSorted = true;
	bool	vectorSorted = true;

	std::list<int>::iterator	indexList = this->_ListTrie.begin();
	std::list<int>::iterator	previousIndexList = indexList;
	++indexList;
	for (; listSorted && indexList != this->_ListTrie.end(); indexList++, previousIndexList++)
	{
		if (*previousIndexList > *indexList)
			listSorted = false;
	}

	for (int i = 1; vectorSorted && i < this->_nbrOfElement; i++)
	{
		if (this->_VectorTrie[i - 1] > this->_VectorTrie[i])
			vectorSorted = false;
	}
	if (show)
	{
		if (!listSorted)
			std::cout << RED "List n'est pas trie :(" NOCOLOR << std::endl;
		if (!vectorSorted)
			std::cout << RED "Vector n'est pas trie :(" NOCOLOR << std::endl;
		if (listSorted && vectorSorted)
			std::cout << GREEN "Les 2 contenaire sont trier :D" NOCOLOR << std::endl;
	}
	return (listSorted && vectorSorted);
}

void PmergeMe::exec(bool show)
{
	this->_isSorted(show);
	int	lenshow = 5;
	// std::cout << "nbr of element : " << this->_nbrOfElement << std::endl;
	std::cout << "Before:\t";
	this->_showContenair(lenshow);

	double	timeList = this->_sortListTime();
	double	timeVector = this->_sortVectorTime();
	std::cout << "After:\t";
	this->_showContenair(lenshow);
	std::cout << "Time to process a range of\t" << this->_nbrOfElement << " elements with std::list<int>  :\t" << timeList << " us" << std::endl;
	std::cout << "Time to process a range of\t" << this->_nbrOfElement << " elements with std::vector<int> :\t" << timeVector << " us" << std::endl;
	this->_isSorted(show);
}


double	PmergeMe::_sortVectorTime(void)
{
	std::clock_t start = std::clock();

	if (!this->_isSorted(false))
		this->_VectorTrie = this->_sortVector(this->_VectorTrie.begin(), --this->_VectorTrie.end() , this->_VectorTrie.size());
	
	std::clock_t end = std::clock();
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
}

double	PmergeMe::_sortListTime(void)
{
	std::clock_t start = std::clock();

	if (!this->_isSorted(false))
		this->_ListTrie = this->_sortList(this->_ListTrie.begin(), --this->_ListTrie.end() , this->_ListTrie.size());

	std::clock_t end = std::clock();
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
}

std::vector<int>	PmergeMe::_sortVector(std::vector<int>::iterator First , std::vector<int>::iterator Last, size_t len)
{
	std::vector<int> Fusion;
	if (len <= 1)
	{
		Fusion.push_back(*First);
		return (Fusion);
	}
	if (len == 2)
	{
		if (*First > *Last)
			std::iter_swap(Last, First);
		Fusion.push_back(*First);
		Fusion.push_back(*Last);
		return (Fusion);
	}
	size_t	moitier_Droite = len / 2;
	size_t	moitier_Gauche = len - moitier_Droite;
	std::vector<int>::iterator	LastLeft = First + moitier_Gauche - 1;
	std::vector<int>::iterator	FirstRight = LastLeft + 1;

	std::vector<int> Left = this->_sortVector(First, LastLeft, moitier_Gauche);
	std::vector<int> Right = this->_sortVector(FirstRight, Last, moitier_Droite);

	std::vector<int>::iterator IndexLeft = Left.begin();
	std::vector<int>::iterator IndexRight = Right.begin();
	for (; IndexLeft != Left.end() && IndexRight != Right.end();)
	{
		if (*IndexLeft < *IndexRight)
		{
			Fusion.push_back(*IndexLeft);
			IndexLeft++;
		}
		else
		{
			Fusion.push_back(*IndexRight);
			IndexRight++;
		}
	}
	for (; IndexLeft != Left.end(); IndexLeft++)
		Fusion.push_back(*IndexLeft);
	for (; IndexRight != Right.end(); IndexRight++)
		Fusion.push_back(*IndexRight);
	return (Fusion);
}

std::list<int>	PmergeMe::_sortList(std::list<int>::iterator First , std::list<int>::iterator Last, size_t len)
{
	std::list<int> Fusion;
	if (len <= 2)
	{
		if (len == 2 && *First > *Last)
			std::iter_swap(Last, First);
		Fusion.push_back(*First);
		if (len == 2)
			Fusion.push_back(*Last);
		return (Fusion);
	}

	size_t	moitier_Droite = len / 2;
	size_t	moitier_Gauche = len - moitier_Droite;
	std::list<int>::iterator LastLeft = First;
	std::advance(LastLeft, moitier_Gauche);
	std::list<int>::iterator	FirstRight = LastLeft;
	FirstRight++;

	std::list<int> Left = this->_sortList(First, LastLeft, moitier_Gauche);
	std::list<int> Right = this->_sortList(FirstRight, Last, moitier_Droite);

	std::list<int>::iterator IndexLeft = Left.begin();
	std::list<int>::iterator IndexRight = Right.begin();

	while (IndexLeft != Left.end() && IndexRight != Right.end())
	{
		if (*IndexLeft < *IndexRight)
		{
			Fusion.push_back(*IndexLeft);
			IndexLeft++;
		}
		else
		{
			Fusion.push_back(*IndexRight);
			IndexRight++;
		}
	}
	while (IndexLeft != Left.end())
	{
		Fusion.push_back(*IndexLeft);
		IndexLeft++;
	}
	while (IndexRight != Right.end())
	{
		Fusion.push_back(*IndexRight);
		IndexRight++;
	}
	return (Fusion);
}
