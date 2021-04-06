/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:37:57 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/13 19:05:53 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "cmath"
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->rawBits = 0;
	return ;
}

Fixed::Fixed(int point)
{
	this->rawBits = point << fracBits;
	return ;
}

Fixed::Fixed(float point)
{
	this->rawBits = roundf(point * (1 << fracBits));
	return ;
}

Fixed::Fixed(const Fixed & instance)
{
	*this = instance;
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed & Fixed::operator=(const Fixed & instaces)
{
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

bool Fixed::operator>(const Fixed & instance) const
{
	if (this->rawBits > instance.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed & instance) const
{
	if (this->rawBits >= instance.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed & instance) const
{
	if (this->rawBits < instance.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed & instance) const
{
	if (this->rawBits <= instance.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed & instance) const
{
	if (this->rawBits == instance.rawBits)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed & instance) const
{
	if (this->rawBits != instance.rawBits)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed & instance) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + instance.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed & instance) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - instance.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed & instance) const
{
	Fixed tmp;

	unsigned int first = this->getRawBits();
	unsigned int second = instance.getRawBits();
	tmp.setRawBits(first * second >> fracBits); 
	return (tmp);
}

Fixed Fixed::operator/(const Fixed & instance) const
{
	Fixed tmp;

	unsigned int first = this->getRawBits() << fracBits;
	unsigned int second = instance.getRawBits();
	tmp.setRawBits(first / second); 
	return (tmp);
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	rawBits++;
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	rawBits--;
	return (old);
}

Fixed & Fixed::operator++(void)
{
	rawBits++;
	return (*this);
}

Fixed & Fixed::operator--(void)
{
	rawBits--;
	return (*this);
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

Fixed & Fixed::min(Fixed & instance1, Fixed & instance2)
{
	if (instance1 <= instance2)
		return (instance1);
	return (instance2);
}

const Fixed & Fixed::min(const Fixed & instance1, const Fixed & instance2)
{
	if (instance1 <= instance2)
		return (instance1);
	return (instance2);
}

Fixed & Fixed::max(Fixed & instance1, Fixed & instance2)
{
	if (instance1 >= instance2)
		return (instance1);
	return (instance2);
}

const Fixed & Fixed::max(const Fixed & instance1, const Fixed & instance2)
{
	if (instance1 >= instance2)
		return (instance1);
	return (instance2);
}
