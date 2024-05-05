/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:53:17 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/05 20:10:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
private:
	std::string _login;
public:
	Student(std::string login) : _login(login)
	{
		std::cout << "Student " << this->_login << " is born" << std::endl;
	}
	~Student()
	{
		std::cout << "Student died" << std::endl;
	}
};

int	main()
{
	Student	bob = Student("bibi");
	Student	*jim = new Student("JIMY");
	
	// FAIRE DES TRUCS

	delete jim;
	return (0);
}