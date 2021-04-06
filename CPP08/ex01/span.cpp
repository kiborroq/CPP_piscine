/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:41:37 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 12:09:25 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm"
#include "iostream"
#include "cstdlib"
#include "climits"
#include "span.hpp"

span::span(unsigned int n) : N(n)
{
	minSpan =  UINT_MAX;
	maxSpan = 0;
	prevSize = 1;
}

span::~span(void) {}

const char *span::TooMuchNumbersException::what(void) const throw()
{
	return ("Numbers of ints are exceeded limit!");
}

const char *span::TooLowNumbersException::what(void) const throw()
{
	return ("Not enough numbers for span calculating!");
}

void span::addNumber(int num)
{
	if (v.size() < N)
	{
		v.push_back(num);
		renewMinMaxSpan();
	}
	else
		throw span::TooMuchNumbersException();
}

void span::renewMinMaxSpan(void)
{
	if (v.size() > 1)
	{
		std::vector<int>::iterator curr = v.begin() + prevSize - 1;
		std::vector<int>::iterator end = v.end();
		unsigned int tmp;

		for ( ; curr + 1 != end; curr++)
		{
			tmp = std::abs(static_cast<long>(*curr) - static_cast<long>(*(curr + 1)));
			if (tmp > maxSpan)
				maxSpan = tmp;
			if (tmp < minSpan)
				minSpan = tmp;
		}
		prevSize = v.size();
	}
}

unsigned int span::shortestSpan(void) const
{
	if (v.size() < 2)
		throw span::TooLowNumbersException();
	return (minSpan);
}

unsigned int span::longestSpan(void) const
{
	if (v.size() < 2)
		throw span::TooLowNumbersException();
	return (maxSpan);
}

unsigned int span::size(void) const
{
	return (v.size());
}
