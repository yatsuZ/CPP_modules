/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:49:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/05 02:57:12 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEMANIP_HPP
# define FILEMANIP_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class FileManip
{
private:
	bool		_goodInit;
	std::string	_fileName;
	std::string	_s1;
	std::string	_s2;
	void	_replaceS1ByS2(std::string line, std::ofstream &outf);
public:
	FileManip(int argc, char **argv);
	~FileManip();
	void	creatReplace(void);
	void	showFileManip(void) const;
};

#endif