/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:10:54 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/14 18:40:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

/////////////////////////////////////////////// Exception

class BitcoinExchange::CantOpenException : public std::exception
{
		virtual const char* what(void) const throw()
		{
			return (RED "Error: could not open file." NOCOLOR);
		}
};

/////////////////////////////////////////////// Canonique + constructeur

BitcoinExchange::BitcoinExchange(void): _fileArg(NULL)
{
}

BitcoinExchange::BitcoinExchange(int argc, char **argv):
_fileArg(argc > 1 ? argv[1] : throw BitcoinExchange::CantOpenException()),
_DataCsv(this->_getDataCsv()),
_FileData(this->_getFileData())
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src): _fileArg(src._fileArg)
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

const std::map<std::string, float> BitcoinExchange::_getDataCsv(void) const
{
	std::map<std::string, float> newMap;
	std::ifstream	input("./data.csv");
	std::string		line;
	bool			first = true;
	if (!input.is_open())
		throw std::runtime_error("Cannot open file");

	while (std::getline(input, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		
		if (std::getline(iss, date, ',') && std::getline(iss, valueStr) && !first)
		{
			// Remove leading and trailing whitespace from date and valueStr
			date.erase(0, date.find_first_not_of(" \n\r\t"));
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));
			valueStr.erase(valueStr.find_last_not_of(" \n\r\t") + 1);
			try
			{
				errno = 0;
				char* endptr;
				float value = static_cast<float>(strtof(valueStr.c_str(), &endptr));
				if (errno == ERANGE || endptr == valueStr.c_str() || *endptr != '\0')
					throw std::invalid_argument("Fail Conversion Invalide input");
				newMap.insert(std::make_pair(date, value));
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << "Invalid value: " << valueStr << std::endl;
			}
		}
		else if (!true)
			std::cerr << "Invalid line format: " << line << std::endl;
		first = false;
	}
	input.close();
	return (newMap);
}

const std::map<std::string, float> BitcoinExchange::_getFileData(void) const
{
	std::map<std::string, float> newMap;
	return (newMap);
}

void	BitcoinExchange::info(void) const
{
	std::cout << YELLOW "INFO du BitcoinExchange :" NOCOLOR << std::endl;
	std::cout << MAGENTA "File argument = " NOCOLOR << this->_fileArg << std::endl;
	this->infoDataCsv();
	std::cout << "---------------------------------------------" << std::endl<< std::endl;
}

void	BitcoinExchange::infoDataCsv(void) const
{
	std::map<std::string, float>::const_iterator it = this->_DataCsv.begin();
	
	for (; it != this->_DataCsv.end(); ++it)
	{
		std::cout << "Date : " << it->first << ", exchange_rate : " << it->second << std::endl;
	}

}
