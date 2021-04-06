/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:06:49 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 16:44:08 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdexcept"
#include "iostream"
#include "Bureaucrat.hpp"

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
	printHeader("Iinitialisation with exceptions test");
	try
	{
		Bureaucrat *b1 = new Bureaucrat("FIRST", 151);
		std::cout << b1;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2("SECOND", 0);
		std::cout << b2;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	printHeader("Decrement with exceptions test");
	Bureaucrat b1("FIRST", 149);
	std::cout << b1;
	try
	{
		b1.decrement();
		std::cout << b1;
		b1.decrement();
		std::cout << b1;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b1;
	std::cout << std::endl;

	printHeader("Decrement with exceptions test");
	Bureaucrat b2("SECOND", 2);
	std::cout << b2;
	try
	{
		b2.increment();
		std::cout << b2;
		b2.increment();
		std::cout << b2;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b2;
	return (0);
}
