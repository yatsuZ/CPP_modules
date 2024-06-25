/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/26 01:26:01 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

PmergeMe::PmergeMe(void):
_VectorTrie(std::vector<int>()),
_DequeTrie(std::deque<int>()),
_nbrOfElement(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &src):
_VectorTrie(src._VectorTrie),
_DequeTrie(src._DequeTrie)
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
_DequeTrie(std::deque<int>()),
_nbrOfElement(argc - 1)
{
	if (!this->_nbrOfElement)
		throw std::invalid_argument("Needs argument positive integer.");
	for (int i = 1; i < argc; i++)
	{
		int res = this->_strToInt(argv[i]);
		this->_VectorTrie.push_back(res);
		this->_DequeTrie.push_back(res);
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_VectorTrie = src._VectorTrie;
		this->_DequeTrie = src._DequeTrie;
	}
	return (*this);
}

////////

void	PmergeMe::_showContenair(size_t len) const
{
	if (this->_VectorTrie.empty())
	{
		std::cout << "EMPTY" << std::endl;
		return ;
	}
	if (!len)
		len = this->_VectorTrie.size();
	std::vector<int>::const_iterator i = this->_VectorTrie.begin();
	for (; i != this->_VectorTrie.end() && len; i++, len--)
	{
		std::cout << *i << " ";
	}
	if (i != this->_VectorTrie.end())
		std::cout << "[...]";
	std::cout << std::endl;
}

bool	PmergeMe::_isSorted(bool show)
{
	bool	dequeSorted = true;
	bool	vectorSorted = true;

	for (int i = 1; i < this->_nbrOfElement && (vectorSorted || dequeSorted); i++)
	{
		if (this->_DequeTrie[i - 1] > this->_DequeTrie[i])
			dequeSorted = false;
		if (this->_VectorTrie[i - 1] > this->_VectorTrie[i])
			vectorSorted = false;
	}
	if (show)
	{
		if (!dequeSorted)
			std::cout << RED "Deque n'est pas trie :(" NOCOLOR << std::endl;
		if (!vectorSorted)
			std::cout << RED "Vector n'est pas trie :(" NOCOLOR << std::endl;
		if (dequeSorted && vectorSorted)
			std::cout << GREEN "Les 2 contenaire sont trier :D" NOCOLOR << std::endl;
	}
	return (dequeSorted && vectorSorted);
}

void PmergeMe::exec(void)
{
	int	lenshow = 5;
	// std::cout << "nbr of element : " << this->_nbrOfElement << std::endl;
	std::cout << "Before:\t";
	this->_showContenair(lenshow);

	double	timeDeque = this->_sortDequeTime();
	double	timeVector = this->_sortVectorTime();
	std::cout << "After:\t";
	this->_showContenair(lenshow);
	std::cout << "Time to process a range of\t" << this->_nbrOfElement << " elements with std::deque<int>  :\t" << timeDeque << " us" << std::endl;
	std::cout << "Time to process a range of\t" << this->_nbrOfElement << " elements with std::vector<int> :\t" << timeVector << " us" << std::endl;
	this->_isSorted(true);
}


double	PmergeMe::_sortVectorTime(void)
{
	std::clock_t start = std::clock();

	if (!this->_isSorted(false))
		this->_VectorTrie = this->_sortVector(this->_VectorTrie.begin(), --this->_VectorTrie.end() , this->_VectorTrie.size());
	
	std::clock_t end = std::clock();
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
}

double	PmergeMe::_sortDequeTime(void)
{
	std::clock_t start = std::clock();

	if (!this->_isSorted(false))
		this->_DequeTrie = this->_sortDeque(this->_DequeTrie.begin(), --this->_DequeTrie.end() , this->_DequeTrie.size());

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

	// std::cout << "LastLeft = " << *LastLeft << " len = " << len << " moitier_Droite = " << moitier_Droite << " moitier_Gauche = " << moitier_Gauche << std::endl;
	std::vector<int> Left = this->_sortVector(First, LastLeft, moitier_Gauche);
	std::vector<int> Right = this->_sortVector(FirstRight, Last, moitier_Droite);

	std::vector<int>::iterator IndexLeft = Left.begin();
	std::vector<int>::iterator IndexRight = Right.begin();
	for (; IndexLeft != Left.end() && IndexRight != Right.end();)
	{
		// std::cout << "IndexLeft = " << *IndexLeft << " IndexRight = " << *IndexRight << std::endl;
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

std::deque<int>	PmergeMe::_sortDeque(std::deque<int>::iterator First , std::deque<int>::iterator Last, size_t len)
{
	std::deque<int> Fusion;
	if (len <= 2)
	{
		if (len == 2 && *First > *Last)
			std::iter_swap(Last, First);
		Fusion.push_back(*First);
		if (len == 2)
			Fusion.push_back(*Last);
		return (Fusion);
	}

	std::deque<int> Left = this->_sortDeque(First, First + len - (len / 2) - 1, len - (len / 2));
	std::deque<int> Right = this->_sortDeque(First + len - (len / 2), Last, len / 2);

	std::deque<int>::iterator IndexLeft = Left.begin();
	std::deque<int>::iterator IndexRight = Right.begin();

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
