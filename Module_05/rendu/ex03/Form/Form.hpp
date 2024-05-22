/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:41:44 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:42:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "./../Bureaucrat/Bureaucrat.hpp"

class Form
{
protected:
	virtual void		actionExecute(void) const = 0;
private:
	void				_signedTrue(void);
	const std::string	_name;
	bool				_signed;
	const int			_gradeSigned;
	const int			_gradeExecuted;
	int					_verifSigned(void) const;
	int					_verifExecuted(void) const;
	void				_verifs(void) const;
public:
// Peut rajouter une exception si le Form est deja signée
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
	Form(void);
	Form(Form const &src);
	Form				&operator=(Form const &src);
	virtual ~Form();

	Form(std::string name, int gradeSigned, int radeExecuted);

	const std::string	getName(void) const;
	bool				getSigned(void) const;
	int					getGradeSigned(void) const;
	int					getGradeExecuted(void) const;

	void				beSigned(Bureaucrat signer);
	void				execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<( std::ostream & o, Form const & rhs);
void	drawLigneTab(std::stringstream &ss, int firstColone, int secondColone);

#endif
