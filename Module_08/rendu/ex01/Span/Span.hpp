/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:51:15 by yzaoui            #+#    #+#             */
/*   Updated: 2024/06/07 14:41:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>

class Span
{
private:
	unsigned int	_n;
	int	*_contenair;
	unsigned int	_place;
	Span();
	unsigned int	getN(void) const;
	unsigned int	getPlace(void) const;
	void			setN(const int n);
	int				*getContenair(void) const;
public:
	Span(int n);
	void			showSpan(void) const;
	~Span();
	Span(const Span &src);
	Span			&operator=(const Span &src);

};

#endif