/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:27:35 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:07:52 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "ZombieEvent.hpp"

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
	printHeader("Zombie on heap (direct)");
	{
		Zombie *newZombie = new Zombie("first", "terrible");
		newZombie->announce();
		delete newZombie;
	}
	std::cout << std::endl << std::endl;


	printHeader("Zombie on stack (direct)");
	{
		Zombie newZombie("second", "stupid");
		newZombie.announce();
	}
	std::cout << std::endl << std::endl;


	printHeader("Zombie by ZombieEvent on heap (newZombie)");
	ZombieEvent ze;
	{
		Zombie *newZombie = ze.newZombie("awesome");
		newZombie->announce();
		delete newZombie;
	}
	std::cout << std::endl << std::endl;

	printHeader("Zombie by ZombieEvent on srack (randomChump)");
	{
		ze.setZombieType("creative");
		ze.randomChump();
		std::cout << std::endl;
		ze.setZombieType("slowly");
		ze.randomChump();
		std::cout << std::endl;
		ze.setZombieType("strong");
		ze.randomChump();
		std::cout << std::endl;
	}
	return (0);
}
