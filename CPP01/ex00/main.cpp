/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:41:55 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 17:52:10 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Phony.hpp"

void printHeader(std::string header)
{
	std::cout	<< "\033[1;35m"
				<< "<<<<< "
				<< header
				<< " >>>>>"
				<< "\033[0m"
				<< std::endl;
}

void	ponyOnTheHeap(void)
{
	Phony *heap = new Phony("Heap", "gray", 5);
	delete heap;
}

void	ponyOnTheStack(void)
{
	Phony stack("Stack", "red", 3);
}

int		main(void)
{
	printHeader("Pony on heap");
	ponyOnTheHeap();
	std::cout << std::endl;

	printHeader("Pony on heap stack");
	ponyOnTheStack();
	return (0);
}
