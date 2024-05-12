/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:29:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/12 18:20:04 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T>// peut metre plusieur autre type
class List
{
private:
	T *			_content;
	List<T> *	_next;
public:
	List<T>( T const & content)
	{
		//etc
	}

	List<T>( List<T> const & content)
	{
		//etc
	}

	~List<T>(void)
	{
		//etc
	}

	// etc...
};

int	main(void)
{
	List< int >		a( 42 );
	List< float >	b( 3.14f );
	List< List< int >> c( a );

	// etc

	return (0);
}