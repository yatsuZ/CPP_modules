/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:59:15 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:50:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "./../Form.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define SHRUBBERY_SIGN 145
#define SHRUBBERY_EXEC 137

class ShrubberyCreationForm: public Form
{
private:
	const std::string		_target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();

	const std::string		getTarget(void) const;
	void					actionExecute(void) const;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);

#endif