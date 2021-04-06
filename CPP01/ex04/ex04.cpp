/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:20:50 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 19:29:24 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"

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
	std::string str = "HI THIS IS BRAIN";

	printHeader("Display string using the pointer");
	{
		std::string *strPtr = &str;
		std::cout << *strPtr << std::endl;
		std::cout << strPtr << std::endl;
	}
	std::cout << std::endl;

	printHeader("Display string using the reference");
	{
		std::string &strRef = str;
		std::cout << strRef << std::endl;
		std::cout << &strRef << std::endl;
	}
	return (0);
}
