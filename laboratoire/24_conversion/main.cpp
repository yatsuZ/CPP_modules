/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/06 00:36:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void dump_32bits_integer(int a) {
	printf("[%10d]: ", a);
	for (int i = 31; i >= 0; i--) {
		putchar((a & (1 << i)) ? '1' : '0');
		if (i % 8 == 0) putchar(' ');
	}
	putchar('\n');
}

void dump_64bits_double(double b) {
	printf("[%10lf]: ", b);
	unsigned long long int *p = (unsigned long long int *)&b;
	for (int i = 63; i >= 0; i--) {
		putchar((*p & ((unsigned long long int)1 << i)) ? '1' : '0');
		if (i == 63 || i == 52) putchar(' ');
	}
	putchar('\n');
}


int	main(void)
{
	int		a = 42;

	double	b = a;
	double	c = (double) a;

	double	d = 13.248f;
	int		e = d;
	int		f = (int) d;

	dump_32bits_integer(a);

	dump_64bits_double(b);
	dump_64bits_double(c);

	dump_64bits_double(d);
	dump_32bits_integer(e);
	dump_32bits_integer(f);


}