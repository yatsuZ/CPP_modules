/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:10:44 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/26 01:32:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pareil que ifndef
#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

class BitcoinExchange
{
private:
	const std::string				_fileArg;
	const std::deque<std::string>	_DataCsv;
	const std::deque<std::string>	_FileData;

///////////////////////////////////////////////// Exception
	class CantOpenException;

///////////////////////////////////////////////// AUTRES
	const std::deque<std::string> _getDataCsv(void) const;
	const std::deque<std::string> _getFileData(void) const;

	void	_verifLine(const std::string line, std::string &date, float &value)const;
	bool	_verifDate(const std::string DateStr)const;

	std::string					_getDateByLine(const std::string line) const;
	float						_getValueByLine(const std::string line) const;
	float						_getTauxDechange(const std::string date) const;
	const std::string			_getLastDate(void) const;
	const std::string			_getFirstDate(void) const;
/////////////////////////////////////////////// Canonique + constructeur
	BitcoinExchange(void);
public:
	BitcoinExchange(int argc, char **argv);
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

///////////////////////////////////////////////// AUTRES
	void	info(void) const;
	void	infoDataCsv(int loop) const;
	void	infoDataInput(int loop) const;
	void	exec(void) const;

};
