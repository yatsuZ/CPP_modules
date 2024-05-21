/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:55 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/20 22:25:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include "./../Form/Form.hpp"

#include <iostream>
#include <string.h>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

#define HIGHEST 1
#define LOWEST 150

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();
	Bureaucrat	&operator=(Bureaucrat const &src);


	Bureaucrat(std::string name, int grade);
	const std::string	getName(void) const;
	int					getGrade(void) const;
	void				showData(void) const;

	void				setGrade(const int newGrade);
	void				upGrade(void);
	void				downGrade(void);
private:
	const std::string			_name;
	int							_grade;
	void						_verif(void) const;
	class GradeTooLowException : public std::exception
	{
		private:
			const std::string	_msg;
		public :
			GradeTooLowException(std::string name): _msg("Grade over 150 of " + name + " is to Low !!")
			{}
			virtual ~GradeTooLowException() throw() {}
			virtual const char* what(void) const throw()
			{
				return (this->_msg.c_str());
			}
	};
	class GradeTooHighException : public std::exception
	{
		private:
			const std::string	_msg;
		public :
			GradeTooHighException(const std::string name): _msg("Grade less 1 of " + name + " is to High !!")
			{}
			virtual ~GradeTooHighException() throw() {}
			virtual const char* what(void) const throw()
			{
				return (this->_msg.c_str());
			}
	};
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif