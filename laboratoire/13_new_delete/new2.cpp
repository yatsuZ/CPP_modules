/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:59:54 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 03:01:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
private:
	std::string _login;
public:
	Student() : _login("ldefault")
	{
		std::cout << "Student " << this->_login << "is born" << std::endl;
	}
	~Student()
	{
		std::cout << "Student died" << std::endl;
	}
};

int	main()
{
	Student	*students = new Student[42];
	
	// FAIRE DES TRUCS

	delete [] students;
	return (0);
}