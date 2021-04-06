/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:37:57 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/13 19:24:17 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "cmath"
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
	return ;
}

Fixed::Fixed(int point)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = point << fracBits;
	return ;
}

Fixed::Fixed(float point)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(point * (1 << fracBits));
	return ;
}

Fixed::Fixed(const Fixed & instance)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(const Fixed & instaces)
{
	std::cout << "Assignation operator called" << std::endl;
	this->rawBits = instaces.getRawBits();
	return (*this);
}

int Fixed::toInt(void) const
{
	return (rawBits >> fracBits);
}

float Fixed::toFloat(void) const
{
	return ((float)rawBits / (1 << fracBits));
}

int Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void Fixed::setRawBits(const int & rawBits)
{
	this->rawBits = rawBits;
}

std::ostream & operator<<(std::ostream & out, const Fixed & instance)
{
	out << instance.toFloat();
	return (out);
}
