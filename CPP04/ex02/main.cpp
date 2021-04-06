/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:21:59 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/19 17:21:01 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

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
	printHeader("Create MARINES and push ones to new SQUAD1");
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* tom = new TacticalMarine;
	ISpaceMarine* kit = new AssaultTerminator;
	Squad* squad1 = new Squad;
	squad1->push(bob);
	squad1->push(jim);
	squad1->push(tom);
	squad1->push(kit);
	std::cout << "SQOAD1 COUNT = " << squad1->getCount() << std::endl;
	std::cout << std::endl;

	printHeader("Try push null and already in SQUAD1 MARINES");
	squad1->push(bob);
	squad1->push(NULL);
	std::cout << "SQOAD1 COUNT = " << squad1->getCount() << std::endl;
	std::cout << std::endl;

	printHeader("Create new SQUAD2 by assignation SQUAD1");
	Squad squad2 = *squad1;
	std::cout << "SQOAD2 COUNT = " << squad2.getCount() << std::endl;
	std::cout << std::endl;

	printHeader("Create new SQUAD3 by copy SQUAD2");
	Squad squad3(squad2);
	std::cout << "SQOAD3 COUNT = " << squad3.getCount() << std::endl;
	std::cout << std::endl;

	printHeader("Recreate SQUAD2 by assignation SQUAD3");
	squad2 = squad3;
	std::cout << "SQOAD2 COUNT = " << squad2.getCount() << std::endl;
	std::cout << std::endl;

	printHeader("Attack test for SQUAD1");
	for (int i = 0; i < squad1->getCount(); ++i)
	{
		ISpaceMarine* cur = squad1->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << std::endl;

	printHeader("Attack test for SQUAD2");
	for (int i = 0; i < squad2.getCount(); ++i)
	{
		ISpaceMarine* cur = squad2.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << std::endl;

	printHeader("Attack test for SQUAD3");
	for (int i = 0; i < squad3.getCount(); ++i)
	{
		ISpaceMarine* cur = squad3.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << std::endl;

	printHeader("Delete SQUAD(1,2,3)");
	delete squad1;
	return (0);
}
