/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:16:47 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 23:34:20 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

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
	printHeader("SORCERER CLASS CONSTRUCTOR and DESTRUCTOR");
	{
		Sorcerer s1("Anton", "slowly");
		Sorcerer s2 = s1;
		Sorcerer s3(s2);
		std::cout << std::endl;

		std::cout << s1;
		std::cout << s2;
		std::cout << s3;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	printHeader("VICTIM CLASS CONSTRUCTOR and DESTRUCTOR");
	{
		Victim v1("Victor");
		Victim v2 = v1;
		Victim v3(v2);
		std::cout << std::endl;

		std::cout << v1;
		std::cout << v2;
		std::cout << v3;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	printHeader("PEON CLASS CONSTRUCTOR and DESTRUCTOR (direct)");
	{
		Peon p1("Boris");
		Peon p2 = p1;
		Peon p3(p2);
		std::cout << std::endl;

		std::cout << p1;
		std::cout << p2;
		std::cout << p3;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	printHeader("Functionality test");
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("DIRECT-PEON");
		Victim *karl = new Peon("THROUGH-VICTIM-PEON");
		std::cout << std::endl;

		robert.polymorph(jim);
		robert.polymorph(joe);
		robert.polymorph(*karl);
		std::cout << std::endl;

		delete karl;
	}
	return (0);
}
