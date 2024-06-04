/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:51:15 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/04 17:21:40 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>

class Span
{
private:
	int	_n;
	Span();
public:
	Span(int n);
	~Span();
	Span(const Span &src);
	Span	&operator=(const Span &src);

	int	getN(void) const;
	void	setN(const int n);
};

#endif