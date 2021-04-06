/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:29:46 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/13 19:31:14 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 9999.99f ) / Fixed( 3 ) );

	std::cout << "a           " << a << std::endl;
	std::cout << "++a         " << ++a << std::endl;
	std::cout << "a           " << a << std::endl;
	std::cout << "a++         " << a++ << std::endl;
	std::cout << "a           " << a << std::endl;
	std::cout << "b           " << b << std::endl;
	std::cout << "max(a, b)   " << Fixed::max( a, b ) << std::endl;
	std::cout << "c           " << c << std::endl;
	std::cout << "min(b, c)   " << Fixed::min( b, c ) << std::endl;

	std::cout << std::endl;

	std::cout << std::boolalpha;
	std::cout << "a=" << a << " b=" << b << " c=" << c << std::endl; 
	std::cout << "a < c       " << (a < c) << std::endl;
	std::cout << "a > c       " << (a > c) << std::endl;
	std::cout << "a == a      " << (a == a) << std::endl;
	std::cout << "a == b      " << (a == b) << std::endl;
	std::cout << "c != b      " << (c != b) << std::endl;
	std::cout << "c != c      " << (c != c) << std::endl;

	return (0);
}
