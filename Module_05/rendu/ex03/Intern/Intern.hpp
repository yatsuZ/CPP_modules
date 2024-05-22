/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:14:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:54:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "./../Form/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "./../Form/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "./../Form/ShrubberyCreationForm/ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &src);
	Intern	&operator=(Intern const &src);
	~Intern();

	Form	*makeForm(const std::string name, const std::string target);
	class DontFindForm : public std::exception
	{
		private:
			const std::string	_msg;
		public :
			DontFindForm(std::string name): _msg("Intern: No find this Form -> " + name)
			{}
			virtual ~DontFindForm() throw() {}
			virtual const char* what(void) const throw()
			{
				return (this->_msg.c_str());
			}
	};
};

#endif