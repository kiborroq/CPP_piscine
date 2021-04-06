/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:01:46 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 12:17:06 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "iomanip"
#include "easyfind.hpp"
#include "vector"
#include "list"
#include "set"

void fill(int & elem)
{
	static int num;
	if (!num)
		num = -42;
	elem = num++;
}

int main(void)
{
	std::ostream_iterator<int, char> oit(std::cout, " ");
	{
		std::vector<int>::iterator occurrence;

		std::vector<int> v(42);
		std::for_each(v.begin(), v.end(), fill);
		std::cout << "source vector:   ";
		std::copy(v.begin(), v.end(), oit);
		std::cout << std::endl;

		std::cout << "occurrence(-5):  ";
		occurrence = easyfind(v, -5);
		std::copy(occurrence, v.end(), oit);
		std::cout << std::endl;

		std::cout << "occurrence(155): ";
		try { occurrence = easyfind(v, 155); }
		catch(const std::exception & e) { std::cout << e.what() << std::endl; }
	}
	std::cout << std::endl;
	{
		std::list<int>::iterator occurrence;

		std::list<int> l;
		l.push_back(4985734);
		l.push_back(365);
		l.push_back(45);
		l.push_back(555);
		l.push_back(1);
		l.push_back(-5);
		l.push_back(1);
		l.push_back(-29349384);
		l.push_back(1);
		l.push_back(-3);
		std::cout << "source list:     ";
		std::copy(l.begin(), l.end(), oit);
		std::cout << std::endl;

		std::cout << "occurrence(1):   ";
		occurrence = easyfind(l, 1);
		std::copy(occurrence, l.end(), oit);
		std::cout << std::endl;

		std::cout << "occurrence(0):   ";
		try { occurrence = easyfind(l, 0); }
		catch(const std::exception & e) { std::cout << e.what() << std::endl; }
	}
	std::cout << std::endl;
	{
		std::set<int>::iterator occurrence;

		std::set<int> s;
		s.insert(111);
		s.insert(45111);
		s.insert(41);
		s.insert(-492);
		s.insert(33);
		s.insert(0);
		std::cout << "source set:      ";
		std::copy(s.begin(), s.end(), oit);
		std::cout << std::endl;

		std::cout << "occurrence(33):  ";
		occurrence = easyfind(s, 33);
		std::copy(occurrence, s.end(), oit);
		std::cout << std::endl;

		std::cout << "occurrence(-22): ";
		try { occurrence = easyfind(s, -22); }
		catch(const std::exception & e) { std::cout << e.what() << std::endl; }
	}
	return (0);
}
