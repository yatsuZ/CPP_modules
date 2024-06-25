/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:30:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/25 17:50:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <exception>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

class RPN
{
private:
	std::string			_Expression;
	std::stack<long>	_contenaire;

	void	_adition(void);
	void	_soustraction(void);
	void	_multiplcation(void);
	void	_division(void);

	void	_verifExpression(void) const;
	RPN(void);
public:
	RPN(int argc, char **argv);
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
	~RPN();

	void	show(bool) const;
	void	showContenaire(void) const;
	void	exec(void);
};

#endif