/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:02:16 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 22:32:00 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdexcept"
#include "iostream"
#include "Array.hpp"

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
		std::string  name;
	public:
		Human(void) {}
		~Human(void) {}
		Human & operator=(std::string const & n) { name = n; return (*this); }
		Human & operator=(Human const & h) { name = h.getName(); return (*this); }
		std::string getName(void) const { return (name); }
};

std::ostream & operator<<(std::ostream & out, Human const & h) 
{
	std::cout << h.getName();
	return (out);
}

template <typename T>
void iter(Array<T> const & array, unsigned int size, void(*f)(T const &))
{
	try
	{
		for (unsigned int i = 0; i < size; i++)
			f(array[i]);
	}
	catch (std::exception const & e)
	{
		std::cout << "Index out of range!" << std::endl;
	}
}

template< typename T >
void print( T const & x ) { std::cout << x << " "; return; }

template< typename T >
void doTest(Array<T>  *arr1, Array<T> *arr2)
{
	Array<T> arr;
	std::cout << "arr[0]:     ";
	try { std::cout << arr[0] << std::endl; }
	catch (std::exception const & e)
	{ std::cout << "Index out of range!" << std::endl; }

	std::cout << "arr[1]:     ";
	try { std::cout << arr[1] << std::endl; }
	catch (std::exception const & e)
	{ std::cout << "Index out of range!" << std::endl; }

	std::cout << "arr1:       ";
	iter( *arr1, arr1->size(), print );
	std::cout << std::endl;

	std::cout << "arr2:       ";
	iter( *arr2, arr2->size(), print );
	std::cout << std::endl;

	Array<T> arr3(*arr1);
	std::cout << "arr3(arr1): ";
	iter( arr3, arr3.size(), print );
	std::cout << std::endl;

	arr3 = *arr2;
	std::cout << "arr3=arr2:  ";
	iter( arr3, arr3.size(), print );
	std::cout << std::endl;
}

int main(void)
{
	printHeader("Int tests...");
	{
		Array<int> arr1(50);
		for (unsigned int i = 0; i < arr1.size(); i++)
			arr1[i] = i + 1;
		Array<int> arr2(25);
		for (unsigned int i = 0; i < arr2.size(); i++)
			arr2[i] = -(i + 1);
		doTest(&arr1, &arr2);
	}
	std::cout << std::endl;

	printHeader("Float tests...");
	{
		Array<float> arr1(6);
		for (unsigned int i = 0; i < arr1.size(); i++)
			arr1[i] = i + 1.5;
		Array<float> arr2(8);
		for (unsigned int i = 0; i < arr2.size(); i++)
			arr2[i] = -(i + 1.5);
		doTest(&arr1, &arr2);
	}
	std::cout << std::endl;

	printHeader("Char tests...");
	{
		Array<char> arr1(26);
		for (unsigned int i = 0; i < arr1.size(); i++)
			arr1[i] = i + 'a';
		Array<char> arr2(13);
		for (unsigned int i = 0; i < arr2.size(); i++)
			arr2[i] = i + 'A';
		doTest(&arr1, &arr2);
	}
	std::cout << std::endl;

	printHeader("Human tests...");
	{
		Array<Human> arr1(10);
		for (unsigned int i = 0; i < arr1.size(); i++)
			arr1[i] = "Ahuman";
		Array<Human> arr2(15);
		for (unsigned int i = 0; i < arr2.size(); i++)
			arr2[i] = "Bhuman";
		doTest(&arr1, &arr2);
		// const Array <Human> arr3(arr2);
		// iter( arr3, arr3.size(), print );
	}
	return (0);
}
