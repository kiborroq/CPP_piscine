/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:58:45 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 16:46:16 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "FragTrap.hpp"

int main(void)
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
	return (0);
}
