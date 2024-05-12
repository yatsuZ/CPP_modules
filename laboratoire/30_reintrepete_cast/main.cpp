/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/12 16:43:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Parent	{ public: virtual ~Parent( void ) {}};

int	main(void)
{
	float	a = 420.042f;

	void * b = &a;
	int * c = reinterpret_cast<int *>(b);
	int & d = reinterpret_cast<int &>(b);
	Parent &e = reinterpret_cast<Parent &>(b);// sa passe mais sa va faire de la D
	return (0);
}
