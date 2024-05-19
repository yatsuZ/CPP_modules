/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:23:55 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/20 00:09:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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
	int					_grade;
	void				_verif(void) const;
	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw()
			{
				return ("Grade is to Low !!");
			}
	};
	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw()
			{
				return ("Grade is to High !!");
			}
	};
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif