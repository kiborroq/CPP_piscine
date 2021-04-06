/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:08:30 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:00:21 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void printHeader(std::string header)
{
	std::cout	<< "\033[1;35m"
				<< "<<<<< "
				<< header
				<< " >>>>>"
				<< "\033[0m"
				<< std::endl;
}

int main(void)
{
	printHeader("Sign and execute grades validation test!");
	try
	{
		Form f1("tmp", 0, 10);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form f1("tmp", 10, 151);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	printHeader("Form signing test!");
	Bureaucrat boss("BOSS", 1);
	std::cout << boss << std::endl;
	Bureaucrat man("MAN", 130);
	std::cout << man << std::endl;
	Form f1("MAIN", 5, 10);
	std::cout << f1 << std::endl;
	Form f2("NOT MAIN", 130, 140);
	std::cout << f2 << std::endl;

	man.signForm(f1);
	man.signForm(f2);
	
	boss.signForm(f1);
	boss.signForm(f2);

	return (0);
}
