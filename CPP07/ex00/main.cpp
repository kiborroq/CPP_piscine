/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:44:50 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 22:32:24 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "whatever.hpp"

template <typename T>
void doTests(T a, T b)
{
	std::cout << "Source: ";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "swap(a, b): ";
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

void printHeader(std::string header)
{
	std::cout	<< "\033[1;35m"
				<< "<<<<< "
				<< header
				<< " >>>>>"
				<< "\033[0m"
				<< std::endl;
}


class Human
{
	private:
		std::string name;
		unsigned int age;
	public:
		Human(std::string const & n, unsigned int a) : name(n), age(a) {}
		~Human(void) {}
		bool operator<(Human const & h) const { return(this->age < h.getAge()); }
		bool operator>(Human const & h) const { return(this->age > h.getAge()); }
		bool operator==(Human const & h) const { return(this->age == h.getAge()); }
		unsigned int getAge(void) const { return (age); }
		std::string getName(void) const { return (name); }
};

std::ostream & operator<<(std::ostream & out, Human const & h) 
{
	std::cout << h.getName() << " " << h.getAge();
	return (out);
}

// class Awesome {
// public:
// Awesome( int n ) : _n( n ) {}
// bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
// bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
// bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
// bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
// bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
// bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
// int getN(void) const {return _n;}
// private:
// int _n;
// };

// std::ostream & operator<<(std::ostream & out, Awesome const & a) 
// {
// 	std::cout << a.getN();
// 	return (out);
// }

int main(void)
{
	printHeader("Test with INT");
	doTests(static_cast<int>( -55 ), static_cast<int>( 55 ));
	std::cout << std::endl;

	printHeader("Test with FLOAT");
	doTests(static_cast<float>( -55.55f ), static_cast<float>( 55.55f ));
	std::cout << std::endl;

	printHeader("Test with DOUBLE");
	doTests(static_cast<double>( -111.111 ), static_cast<double>( 111.111 ));
	std::cout << std::endl;

	printHeader("Test with CHAR");
	doTests(static_cast<char>( 'A' ), static_cast<char>( 'Z' ));
	std::cout << std::endl;

	printHeader("Test with STRING");
	doTests(std::string( "AAAAAAAAAA" ), std::string( "ZZZZZZZZZZ" ));
	std::cout << std::endl;

	printHeader("Test with HUMAN age1 == age2");
	doTests(Human("SECOND", 25), Human("FIRST", 25));
	std::cout << std::endl;

	printHeader("Test with HUMAN age1 != age2");
	doTests(Human("SECOND", 45), Human("FIRST", 15));

	printHeader("Test with AWESOME");
	doTests(Awesome(45), Awesome(15));
}
