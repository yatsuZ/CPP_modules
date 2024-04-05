/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:54:50 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/05 02:57:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManip.hpp"

FileManip::FileManip(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "ERROR we need only 4 argument !" << std::endl;
		this->_goodInit = false;
		return ;
	}
	this->_fileName = argv[1];
	this->_s1 = argv[2];
	this->_s2 = argv[3];
	this->_goodInit = true;
}

FileManip::~FileManip()
{
}

void	FileManip::showFileManip(void) const
{
	std::string	yellow = "\033[33m";
	std::string	no_color = "\033[0m";

	std::cout << yellow << "this->_goodInit = " << no_color << this->_goodInit << std::endl;
	std::cout << yellow << "this->_fileName = " << no_color << this->_fileName << std::endl;
	std::cout << yellow << "this->_s1 = " << no_color << this->_s1 << std::endl;
	std::cout << yellow << "this->_s2 = " << no_color << this->_s2 << std::endl;
}

void	FileManip::creatReplace(void)
{
	if (this->_goodInit == false)
		return ;
	
	std::string				line;
	std::ifstream			inf(this->_fileName.c_str());
	if (inf.fail())
	{
		std::cout << "Fail for std::ifstream inf("<< this->_fileName << ")" << std::endl;
		inf.close();
		return ;
	}
	std::ofstream	outf((this->_fileName + ".replace").c_str());
	if (inf.fail())
	{
		std::cout << "Fail for std::ofstream outf("<< this->_fileName << ".replace)" << std::endl;
		outf.close();
		inf.close();
		return ;
	}
	while (std::getline(inf, line))
	{
		this->_replaceS1ByS2(line, outf);
		outf << std::endl;
	}
	outf.close();
	inf.close();
}


// Compare tout les s1 caratere et le remplace par s2
void	FileManip::_replaceS1ByS2(std::string line, std::ofstream &outf)
{
	std::string	buff;
	size_t		size = this->_s1.length();

	if (line.length() < size || size <= 0)
	{
		outf << line;
		return ;
	}
	for (size_t debut = 0; debut <= line.length(); debut = debut + size)
	{
		if (debut + size >= line.length())
		{
			outf << line.substr(debut);
			return ;
		}
		else
		{
			buff = line.substr(debut, size);
			if (buff == this->_s1)
				buff = this->_s2;
			outf << buff;
		}
	}
}
