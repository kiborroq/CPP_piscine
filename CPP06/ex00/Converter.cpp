/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:32:16 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 16:13:26 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "stdexcept"
#include "cmath"
#include "limits"
#include "climits"
#include "cfloat"
#include "Converter.hpp"

Converter::Converter(void)
{
	error = false;
	ischar = false;
	isspec = false;
}

Converter::Converter(Converter const & c) { (void)c; }
Converter::~Converter(void) {}
Converter & Converter::operator=(Converter const & c) { (void)c; return (*this); }

void Converter::display(std::string const src)
{
	try
	{
		if (!(ischar = isChar(src)))
		{
			size_t idx;
			d = std::stold(src, &idx);
			std::string tmp = src.substr(idx);
			if (!tmp.empty() && !isFloat(tmp))
				throw std::invalid_argument(src);
			isspec = std::isnan(d) || std::isinf(d);
		}
		else
			c = src[0];
	}
	catch(...)
	{
		error = true;
	}
	castValues();
}

bool Converter::isChar(std::string const & ch)
{
	if (ch.length() == 1 && (ch[0] < '0' || ch[0] > '9'))
		return (true);
	return (false);
}

bool Converter::isFloat(std::string const & suffix)
{
	if (suffix.length() == 1 && suffix[0] == 'f')
		return (true);
	return (false);
}

void Converter::castValues(void)
{
	castChar();
	castInt();
	castFloat();
	castDouble();
}

void Converter::castChar(void)
{
	std::cout << "char: ";
	if (ischar && c <= CHAR_MAX && c >= CHAR_MIN)
		tryPrintChar(c);
	else if (!ischar && !error && !isspec && d <= CHAR_MAX && d >= CHAR_MIN)
		tryPrintChar(static_cast<char>(d));
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void Converter::tryPrintChar(char c)
{
	if (isprint(c))
		std::cout << c;
	else
		std::cout << "Non displayable";
}

void Converter::castInt(void)
{
	std::cout << "int: ";
	if (ischar)
		std::cout << static_cast<int>(c);
	else if (!error && !isspec && d <= INT_MAX && d >= INT_MIN)
		std::cout << static_cast<int>(d);
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void Converter::castFloat(void)
{
	std::cout << "float: ";
	if (ischar)
		std::cout << static_cast<float>(c) << addPrecision(c) << "f";
	else if (!error)
		std::cout << static_cast<float>(d) << addPrecision(d) << "f";
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void Converter::castDouble(void)
{
	std::cout << "double: ";
	if (ischar)
		std::cout << static_cast<double>(c) << addPrecision(c);
	else if (!error)
		std::cout << d << addPrecision(d);
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

std::string Converter::addPrecision(double d)
{
	if (d - static_cast<int>(d) == 0.0)
		return (".0");
	return ("");
}
