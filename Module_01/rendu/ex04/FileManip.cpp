/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:54:50 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 19:57:45 by yzaoui           ###   ########.fr       */
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

void	FileManip::creatReplace(void) const
{
	if (this->_goodInit == false)
		return ;
	
	std::string		tmp;
	std::ifstream	inf(this->_fileName.c_str());
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
	while (inf >> tmp)
	{
		if (tmp == this->_s1)
			outf << this->_s2;
		else
			outf << tmp;
	}
	outf.close();
	inf.close();
}
