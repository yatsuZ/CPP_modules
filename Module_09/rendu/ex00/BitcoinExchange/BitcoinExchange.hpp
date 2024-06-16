/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:10:44 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/17 00:40:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pareil que ifndef
#pragma once

#include <iostream>
#include <string>
#include <vector>
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
	const std::string										_fileArg;
	const std::vector<std::string>	_DataCsv;
	const std::vector<std::string>	_FileData;

///////////////////////////////////////////////// Exception
	class CantOpenException;

///////////////////////////////////////////////// AUTRES
	const std::vector<std::string> _getDataCsv(void) const;
	const std::vector<std::string> _getFileData(void) const;


	bool	_verifInputFile(void)const;
	bool	_verifLine(const std::string line, bool firstLine)const;
	bool	_verifDate(const std::string DateStr, const std::string FirstDate, const std::string LastDate)const;
	bool	_verifValue(const std::string DateStr, const std::string FirstDate, const std::string LastDate)const;

	const std::string	_getDateByLine(const std::string line);
	float				_getValueByLine(const std::string line);
	float				_getTauxDechange(const std::string date);
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
