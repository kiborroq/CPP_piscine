/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:58:45 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 16:46:46 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void printHeader(std::string header)
{
	std::cout	<< "\033[1;35m"
				<< "<<<<< "
				<< header
				<< " >>>>>"
				<< "\033[0m"
				<< std::endl;
}

void fragTrapTest(void)
{
	FragTrap *Conoco = new FragTrap("Conoco");
	FragTrap *R2D2 = new FragTrap("R2D3");
	std::cout << std::endl;

	Conoco->vaulthunter_dot_exe(R2D2->getName());
	R2D2->takeDamage(Conoco->getRandomDamage());
	std::cout << std::endl;

	Conoco->vaulthunter_dot_exe(R2D2->getName());
	R2D2->takeDamage(Conoco->getRandomDamage());
	std::cout << std::endl;

	R2D2->beRepaired(25);
	std::cout << std::endl;

	Conoco->vaulthunter_dot_exe(R2D2->getName());
	R2D2->takeDamage(Conoco->getRandomDamage());
	std::cout << std::endl;

	Conoco->vaulthunter_dot_exe(R2D2->getName());
	R2D2->takeDamage(Conoco->getRandomDamage());
	std::cout << std::endl;

	Conoco->vaulthunter_dot_exe(Conoco->getName());
	Conoco->takeDamage(Conoco->getRandomDamage());
	std::cout << std::endl;

	Conoco->rangedAttack(Conoco->getName());
	Conoco->meleeAttack(Conoco->getName());

	delete Conoco;
	delete R2D2;
}

void scavTrapTest(void)
{
	ScavTrap *Conoco = new ScavTrap("Conoco");
	ScavTrap *R2D2 = new ScavTrap("R2D3");
	ScavTrap *Ferrari = new ScavTrap("Ferrari");
	std::cout << std::endl;

	Conoco->challengeNewcomer();
	Conoco->challengeNewcomer();
	Conoco->challengeNewcomer();
	Conoco->challengeNewcomer();
	std::cout << std::endl;

	Ferrari->rangedAttack(R2D2->getName());
	R2D2->takeDamage(Ferrari->getRangedDamage());
	std::cout << std::endl;

	Conoco->meleeAttack(R2D2->getName());
	R2D2->takeDamage(Conoco->getMeleeDamage());
	std::cout << std::endl;

	R2D2->beRepaired(100);
	std::cout << std::endl;

	Ferrari->meleeAttack(R2D2->getName());
	R2D2->takeDamage(Ferrari->getMeleeDamage());
	std::cout << std::endl;
	
	Conoco->rangedAttack(R2D2->getName());
	R2D2->takeDamage(Conoco->getRangedDamage());
	std::cout << std::endl;

	Ferrari->rangedAttack(R2D2->getName());
	R2D2->takeDamage(Ferrari->getRangedDamage());
	std::cout << std::endl;

	Conoco->rangedAttack(R2D2->getName());
	R2D2->takeDamage(Conoco->getRangedDamage());
	std::cout << std::endl;

	Ferrari->rangedAttack(R2D2->getName());
	R2D2->takeDamage(Ferrari->getRangedDamage());
	std::cout << std::endl;

	Conoco->meleeAttack(R2D2->getName());
	R2D2->takeDamage(Conoco->getMeleeDamage());
	std::cout << std::endl;

	Ferrari->meleeAttack(R2D2->getName());
	R2D2->takeDamage(Ferrari->getMeleeDamage());
	std::cout << std::endl;

	delete Conoco;
	delete R2D2;
	delete Ferrari;
}

int main(void)
{
	printHeader("FRAGTRAP");
	fragTrapTest();
	std::cout << std::endl;

	printHeader("SCAVTRAP");
	scavTrapTest();
	return (0);
}
