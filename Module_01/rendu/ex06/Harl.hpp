/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:04:13 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/05 14:40:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
	void	_litelFt(std::string level, void (Harl::*ft) (void));
public:
	void	complain(std::string level);
	Harl();
	~Harl();
};

#endif