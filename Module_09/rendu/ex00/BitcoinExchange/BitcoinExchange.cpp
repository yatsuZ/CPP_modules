/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:10:54 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/25 20:27:09 by yzaoui           ###   ########.fr       */
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
_DataCsv(std::list<std::string>()),
_FileData(std::list<std::string>())
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
		//rien y a que des const
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

/////////////////////////////////////////////// Autre

const std::string			BitcoinExchange::_getFirstDate(void) const
{
	std::list<std::string>::const_iterator	line = (this->_DataCsv.begin());
	line++;
	std::string	Date = (*line).substr(0, 10);
	return (Date);
}

const std::string			BitcoinExchange::_getLastDate(void) const
{
	std::reverse_iterator<std::list<std::string>::const_iterator>	line = (this->_DataCsv.rbegin());
	std::string	Date = (*line).substr(0, 10);
	return (Date);
}


bool	BitcoinExchange::_verifDate(const std::string DateStr) const
{

	if (DateStr.empty() || DateStr.length() != 10)
		return (false);
	const std::string year = DateStr.substr(0, 4);
	const std::string month = DateStr.substr(5, 2);
	const std::string day = DateStr.substr(8, 2);
	if (day.empty() || month.empty() || day < "01" || day > "31" || month < "01" || month > "12" || DateStr[4] != '-' || DateStr[7] != '-')
		return (false);
	return (true);
}

// pas de verification pour data csv
const std::list<std::string> BitcoinExchange::_getDataCsv(void) const
{
	std::list<std::string> newVector;
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

const std::list<std::string> BitcoinExchange::_getFileData(void) const
{
	std::list<std::string> newVector;
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
	std::list<std::string>::const_iterator it = this->_DataCsv.begin();

	for (int i = 0; it != this->_DataCsv.end() && (loop > i); ++it, i++)
	{
		std::cout << *it << std::endl;
	}
}

void	BitcoinExchange::infoDataInput(int loop) const
{
	std::list<std::string>::const_iterator it = this->_FileData.begin();

	for (int i = 0; it != this->_FileData.end() && (loop > i); ++it, i++)
	{
		std::cout << *it << std::endl;
	}
}


/////////////////////////

void	BitcoinExchange::exec(void) const
{
	std::string	DateInputFile;
	float		value, exchangeRate, result;
	std::list<std::string>::const_iterator it = this->_FileData.begin();

	if (*it != "date | value")
		throw std::invalid_argument("Invalide header of " + this->_fileArg + YELLOW "\n\""+ *it +"\"" NOCOLOR " is bad header thats the good header\n" GREEN "\"date | value\"");
	it++;
	for (; it != this->_FileData.end(); ++it)
	{
		try
		{
			this->_verifLine(*it, DateInputFile, value);
			exchangeRate = this->_getTauxDechange(DateInputFile);
			result = value * exchangeRate;
			// std::cout << DateInputFile << " => " << value << " * " << exchangeRate << " = " << result << std::endl;
			std::cout << DateInputFile << " => " << value << " = " << result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " RED << e.what() << NOCOLOR << '\n';
		}
	}
}

std::string			BitcoinExchange::_getDateByLine(const std::string line) const
{
	std::string	Date = line.substr(0, 10);
	if (!this->_verifDate(Date))
		throw std::invalid_argument(("bad input => " YELLOW) + line);
	if (Date < this->_getFirstDate())
		throw std::invalid_argument(("Invalide Date => " YELLOW) + line);
	return (Date);
}

float				BitcoinExchange::_getValueByLine(const std::string line) const
{
	std::string	valueStr = line.substr(12);
	valueStr.erase(0, valueStr.find_first_not_of(" \t"));
	valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
	errno = 0;
	char* endptr;
	float value = static_cast<float>(strtof(valueStr.c_str(), &endptr));
	if (errno == ERANGE || endptr == valueStr.c_str() || *endptr != '\0')
		throw std::invalid_argument(("bad input => " YELLOW) + line);
	if (value < 0)
		throw std::invalid_argument("not a positive number.");
	if (value > 1000)
		throw std::invalid_argument("too large a number.");
	return (value);
}

void	BitcoinExchange::_verifLine(const std::string line, std::string &date, float &value)const
{
	date = this->_getDateByLine(line);
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw std::invalid_argument(("bad input => " YELLOW) + line);
	value = this->_getValueByLine(line);
}

float	BitcoinExchange::_getTauxDechange(const std::string date) const
{
	std::list<std::string>::const_iterator it = this->_DataCsv.begin();

	++it;
	std::string	goodline = *it;
	for (; it != this->_DataCsv.end() && (*it).substr(0, 11) < date; ++it)
	{
		goodline = *it;
	}
	std::string	valueStr = goodline.substr(11);
	valueStr.erase(0, valueStr.find_first_not_of(" \t"));
	valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
	errno = 0;
	char* endptr;
	float value = static_cast<float>(strtof(valueStr.c_str(), &endptr));
	return (value);
}
