/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:29:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/22 17:56:56 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	gl_var = 1;
int	f( void ) { return 2;}

namespace	Foo{
	int	gl_var = 3;
	int	f(void) { return 4;}
}

namespace	Bar{
	int	gl_var = 5;
	int	f(void) { return 6;}
}

namespace	Muf = Bar;

int	main(void) {
	printf("gl_var:			[%d]\n", gl_var);// CA et
	printf("f():			[%d]\n\n", f());

	printf("Foo::gl_var:	[%d]\n", Foo::gl_var);
	printf("Foo::f()		[%d]\n\n", Foo::f());

	printf("Bar::gl_var:	[%d]\n", Bar::gl_var);
	printf("Bar::f():		[%d]\n\n", Bar::f());

	printf("::gl_var:		[%d]\n", ::gl_var);// CA IDENTIQUE 
	printf("::f():			[%d]\n", ::f());

	return (0);
}