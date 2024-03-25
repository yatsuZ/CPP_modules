/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:18:31 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 03:27:51 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
private:
	std::string _login;
public:
	Student(std::string const & login) : _login(login){}

	std::string&	getLoginRef(){ return this->_login;}
	std::string const &	getLoginRefConst() const { return this->_login;}

	std::string*	getLoginPtr(){ return &(this->_login);}
	std::string const *	getLoginPtrConst() const { return (&this->_login);}

	~Student()
	{
		std::cout << "Student died" << std::endl;
	}
};


int	main()
{
	Student	bob = Student("bibi");
	Student	jim = Student("JIMY");

	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;

	bob.getLoginRef() = "BOUBA";
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "BABAR";
	std::cout << bob.getLoginRefConst() << std::endl;

	return (0);
}