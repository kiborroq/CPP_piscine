/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:19:30 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/18 23:25:05 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"

void printHeader(std::string header)
{
	std::cout	<< "\033[1;35m"
				<< "<<<<< "
				<< header
				<< " >>>>>"
				<< "\033[0m"
				<< std::endl;
}

int main(void)
{
	printHeader("PLASMARIFLE class test");
	{
		PlasmaRifle p1;
		PlasmaRifle p2 = p1;
		PlasmaRifle p3(p2);
		p1.attack();
		p2.attack();
		p3.attack();
	}
	std::cout << std::endl;

	printHeader("POWERFIST class test");
	{
		PowerFist pf1;
		PowerFist pf2 = pf1;
		PowerFist pf3(pf2);
		pf1.attack();
		pf2.attack();
		pf3.attack();
	}
	std::cout << std::endl;

	printHeader("SUPERMUTANT class test");
	{
		SuperMutant s1;
		SuperMutant s2 = s1;
		SuperMutant s3(s2);
		s1.takeDamage(500);
		std::cout << s1.getHP() << std::endl;
		s2.takeDamage(-200);
		std::cout << s2.getHP() << std::endl;
		s3.takeDamage(50);
		std::cout << s3.getHP() << std::endl;
	}
	std::cout << std::endl;

	printHeader("RADSCORPION class test");
	{
		RadScorpion r1;
		RadScorpion r2 = r1;
		RadScorpion r3(r2);
		r1.takeDamage(500);
		std::cout << r1.getHP() << std::endl;
		r2.takeDamage(-200);
		std::cout << r2.getHP() << std::endl;
		r3.takeDamage(50);
		std::cout << r3.getHP() << std::endl;
	}
	std::cout << std::endl;

	printHeader("FIGHT test");
	{
		Character* first = new Character("FIRST");
		Character* second = new Character("SECOND");
		std::cout << *first;
		std::cout << *second;
		std::cout << std::endl;

		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();

		first->equip(pr);
		second->equip(pf);

		std::cout << *first;
		std::cout << *second;
		std::cout << std::endl;

		Enemy* rad = new RadScorpion();
		std::cout << std::endl;

		first->attack(rad);
		second->attack(rad);
		second->attack(rad);
		std::cout << std::endl;

		std::cout << *first;
		std::cout << *second;
		std::cout << std::endl;

		first->recoverAP();
		first->recoverAP();

		std::cout << *first;
		std::cout << *second;
		std::cout << std::endl;

		Enemy* super = new SuperMutant();
		std::cout << std::endl;

		second->attack(super);
		second->attack(super);
		second->attack(super);
		std::cout << *first;
		std::cout << *second;		
		second->attack(super);
		second->attack(super);
		first->attack(super);
		first->attack(super);
		std::cout << std::endl;

		std::cout << *first;
		std::cout << *second;

		delete first;
		delete second;
		delete pf;
		delete pr;
	}
	return (0);
}
