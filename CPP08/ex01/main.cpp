/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:25:52 by kiborroq          #+#    #+#             */
/*   Updated: 2021/04/04 16:36:27 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "climits"
#include "iomanip"
#include "span.hpp"
#include "algorithm"

void printMinMaxSpan(span const & sp)
{
	try
	{
		std::cout << "size = " << std::setw(5) << sp.size() << ": ";
		std::cout << "shortest = " << sp.shortestSpan() << ", ";
		std::cout << "longest = " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

void fillVectorRandom(int & elem)
{
	elem = -500 + rand() % 1000;
}

int main(void)
{
	span sp(10);
	printMinMaxSpan(sp);
	try
	{
		sp.addNumber(-5);
		printMinMaxSpan(sp);

		sp.addNumber(100); //min
		printMinMaxSpan(sp);

		sp.addNumber(99); //min
		printMinMaxSpan(sp);
		
		sp.addNumber(10);
		printMinMaxSpan(sp);

		sp.addNumber(255);
		printMinMaxSpan(sp);

		sp.addNumber(0);
		printMinMaxSpan(sp);

		sp.addNumber(-5685);
		printMinMaxSpan(sp);

		sp.addNumber(34);
		printMinMaxSpan(sp);

		sp.addNumber(INT_MIN); //max
		printMinMaxSpan(sp);

		sp.addNumber(INT_MAX); //max
		printMinMaxSpan(sp);

		sp.addNumber(4570);
	}
	catch(const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printMinMaxSpan(sp);
	std::cout << "UINT_MAX = " << UINT_MAX << std::endl;
	std::cout << std::endl;

	srand(time(NULL));
	
	span sp1(100000);

	try
	{
		std::vector<int> tmp(100000 + 1);
		sp1.addRange(tmp.begin(), tmp.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int> tmp(100000);
	std::for_each(tmp.begin(), tmp.end(), fillVectorRandom);
	sp1.addRange(tmp.begin(), tmp.end());
	printMinMaxSpan(sp1);
	return (0);
}
