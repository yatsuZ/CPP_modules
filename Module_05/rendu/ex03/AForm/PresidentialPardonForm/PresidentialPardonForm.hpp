/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:18 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 18:20:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "./../AForm.hpp"

#include <unistd.h>

#define PRESIDENT_SIGN 25
#define PRESIDENT_EXEC 5

class PresidentialPardonForm: public AForm
{
private:
	const std::string		_target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);
	~PresidentialPardonForm();

	const std::string		getTarget(void) const;
	void		actionExecute(void) const;

};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs);


#endif