/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:47:18 by kiborroq          #+#    #+#             */
/*   Updated: 2021/04/04 23:33:49 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "mutantstack.hpp"

template <typename T>
void printStack(mutantstack<T> & ms)
{
	typename mutantstack<T>::iterator it = ms.begin();
	typename mutantstack<T>::iterator end = ms.end();

	for (; it != end; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
void printStackReverse(mutantstack<T> & ms)
{
	typename mutantstack<T>::iterator it = --ms.end();
	typename mutantstack<T>::iterator end = ms.begin();

	for (; it != end; it--)
		std::cout << *it << " ";
	std::cout << *it << " ";
	std::cout << std::endl;
}

template<typename T>
void printInfo(mutantstack<T> & ms)
{
	std::cout << "size=" << ms.size() << std::endl;
	std::cout << "top=" << ms.top() << std::endl;
	printStack(ms);
	printStackReverse(ms);
}

int main(void)
{
	mutantstack<int> ms;
	std::cout << "push 11 22 33 44 55 66 77 88 99" << std::endl;
	ms.push(11);
	ms.push(22);
	ms.push(33);
	ms.push(44);
	ms.push(55);
	ms.push(66);
	ms.push(77);
	ms.push(88);
	ms.push(99);
	printInfo(ms);

	std::cout << std::endl;

	std::cout << "pop last four elems" << std::endl;
	ms.pop();
	ms.pop();
	ms.pop();
	ms.pop();
	printInfo(ms);

	return (0);
}
