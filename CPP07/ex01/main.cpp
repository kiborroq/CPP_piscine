/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:33:56 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 22:21:58 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

class Human
{
	private:
		std::string name;
	public:
		Human(void) : name("human") {}
		~Human(void) {}
		std::string getName(void) const { return (name); }
};

std::ostream & operator<<(std::ostream & out, Human const & h) 
{
	std::cout << h.getName();
	return (out);
}

template< typename T >
void print( T const & x ) { std::cout << x << " "; return; }

int main(void)
{
	int tab[10] = { 0, 1, 2, 3, 4, 5, 6, 6, 8, 9 };
	float tab1[10] = { -0.0, -1.1, -2.2, -3.3, -4.4, -5.5, -6.6, -7.7, -8.8, -9.9 };
	char tab2[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
    Human tab3[10];

	std::cout << "int:    ";
    ::iter( tab, 10, print );
	std::cout << std::endl;

	std::cout << "float:  ";
    ::iter( tab1, 10, print );
	std::cout << std::endl;

	std::cout << "char:   ";
    ::iter( tab2, 10, print );
	std::cout << std::endl;

	std::cout << "class:  ";
    ::iter( tab3, 10, print );
	std::cout << std::endl;
    return (0);
}
