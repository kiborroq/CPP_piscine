/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:12:04 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/24 20:45:45 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

class Base
{
	public:
		virtual ~Base(void) {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void)
{
	srand(time(NULL));
	char who = 'A' + rand() % 3;
	std::cout << who;
	if (who == 'A')
		return (new A);
	if (who == 'B')
		return (new B);
	return (new C);
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C";
}

void identify_from_reference(Base & p)
{
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C *>(&p) != NULL)
		std::cout << "C";
}

int main(void)
{
	std::cout << "Source: ";
	Base *knonw = generate();
	std::cout << std::endl;

	std::cout << "From pointer: ";
	identify_from_pointer(knonw);
	std::cout << std::endl;

	std::cout << "From reference: ";
	identify_from_reference(*knonw);
	std::cout << std::endl; 

	delete knonw;
	return (0);
}
