/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:59:59 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/22 19:50:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "./../Form.hpp"

#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define ROBOT_SIGN 72
#define ROBOT_EXEC 45

class RobotomyRequestForm: public Form
{
private:
	const std::string		_target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &src);
	~RobotomyRequestForm();

	const std::string		getTarget(void) const;
	void					actionExecute(void) const;

};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif