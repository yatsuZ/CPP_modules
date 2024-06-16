/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:10:54 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/17 00:44:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

/////////////////////////////////////////////// Exception

class BitcoinExchange::CantOpenException : public std::exception
{
		virtual const char* what(void) const throw()
		{
			return (RED "could not open file." NOCOLOR);
		}
};

/////////////////////////////////////////////// Canonique + constructeur

BitcoinExchange::BitcoinExchange(void):
_fileArg(NULL),
_DataCsv(std::vector<std::string>()),
_FileData(std::vector<std::string>())
{
}

BitcoinExchange::BitcoinExchange(int argc, char **argv):
_fileArg(argc > 1 ? argv[1] : throw BitcoinExchange::CantOpenException()),
_DataCsv(this->_getDataCsv()),
_FileData(this->_getFileData())
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src):
_fileArg(src._fileArg),
_DataCsv(src._DataCsv),
_FileData(src._FileData)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		// autre info a changer
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

/////////////////////////////////////////////// Autre

bool	BitcoinExchange::_verifDate(const std::string DateStr, const std::string FirstDate, const std::string LastDate)const
{
	if (DateStr.empty() || DateStr.length() != 10 || DateStr < FirstDate || DateStr > LastDate )
		return (false);
	const std::string year = DateStr.substr(0, 4);
	const std::string month = DateStr.substr(5, 2);
	const std::string day = DateStr.substr(8, 2);
	if (day.empty() || month.empty() || day < "01" || day > "31" || month < "01" || month > "12" || DateStr[4] != '-' || DateStr[7] != '-')
		return (false);
	return (true);
}

// pas de verification pour data csv
const std::vector<std::string> BitcoinExchange::_getDataCsv(void) const
{
	std::vector<std::string> newVector;
	std::ifstream	input("./data.csv");
	std::string		line;

	if (!input.is_open())
		throw BitcoinExchange::CantOpenException();
	while (std::getline(input, line))
	{
		newVector.push_back(line);
	}
	input.close();
	return (newVector);
}

const std::vector<std::string> BitcoinExchange::_getFileData(void) const
{
	std::vector<std::string> newVector;
	std::ifstream	input(this->_fileArg.c_str());
	std::string		line;

	if (!input.is_open())
		throw BitcoinExchange::CantOpenException();
	while (std::getline(input, line))
	{
		newVector.push_back(line);
	}
	input.close();
	return (newVector);
}

void	BitcoinExchange::info(void) const
{
	std::cout << YELLOW "INFO du BitcoinExchange :" NOCOLOR << std::endl;
	std::cout << MAGENTA "File argument = " NOCOLOR << this->_fileArg << std::endl;
	this->infoDataCsv(10);
	std::cout << "---------------------------------------------" << std::endl<< std::endl;
	this->infoDataInput(10);
	std::cout << "---------------------------------------------" << std::endl<< std::endl;
}

void	BitcoinExchange::infoDataCsv(int loop) const
{
	std::vector<std::string>::const_iterator it = this->_DataCsv.begin();

	for (int i = 0; it != this->_DataCsv.end() && (loop > i); ++it, i++)
	{
		std::cout << *it << std::endl;
	}
}

void	BitcoinExchange::infoDataInput(int loop) const
{
	std::vector<std::string>::const_iterator it = this->_FileData.begin();

	for (int i = 0; it != this->_DataCsv.end() && (loop > i); ++it, i++)
	{
		std::cout << *it << std::endl;
	}
}


/////////////////////////

void	BitcoinExchange::exec(void) const
{
	std::cout << "Pour chaque ligne de input file prendre la date et la valeur" << std::endl;
	std::cout << "Mais avant verifier que chaque ligne et correcte genre comment par date | value et les autre respecte les input" << std::endl;
	std::cout << "Puis verifier positive number et que sa ne depasse pas mille et trouver la date la plus proche" << std::endl;
}
