/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:23:14 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/20 22:07:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "./../Bureaucrat/Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeSigned;
	const int			_gradeExecuted;
	int					_verifSigned(void) const;
	int					_verifExecuted(void) const;
	void				_verifs(void) const;

	class GradeTooLowException : public std::exception
	{
		private:
			const std::string	_msg;
		public :
			GradeTooLowException(std::string name): _msg("From: Grade of " + name + " is to Low !!")
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
			GradeTooHighException(const std::string name): _msg("From: Grade of " + name + " is to High !!")
			{}
			virtual ~GradeTooHighException() throw() {}
			virtual const char* what(void) const throw()
			{
				return (this->_msg.c_str());
			}
	};
public:
	Form(void);
	Form(Form const &src);
	Form				&operator=(Form const &src);
	~Form();

	Form(std::string name, int gradeSigned, int radeExecuted);

	const std::string	getName(void) const;
	bool				getSigned(void) const;
	int			getGradeSigned(void) const;
	int			getGradeExecuted(void) const;

	void	beSigned(Bureaucrat signer);// Change le grade du bureaucrate et mais le signarteur true si suprieru ou egal si trop bah il envoie un throw
};

std::ostream & operator<<( std::ostream & o, Form const & rhs);

#endif
