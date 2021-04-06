/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:23:55 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 19:36:17 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Human.hpp"

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
	printHeader("Display brain adress");

	Human bob("Bob");

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
	return (0);
}
