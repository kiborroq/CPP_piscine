/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:03:13 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:03:32 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "string"
#include "Zombie.hpp"

class ZombieHorde
{
	private:
		Zombie		*horde;
		int			numZombie;
		std::string	type;

		void createHorde(void);
		std::string getRandomName(void);

	public:
		ZombieHorde(int numZombie, std::string type = "standart");
		~ZombieHorde(void);

		void announce(void) const;

		Zombie *getZombieHorde(void) const;
		int getNumZombie(void) const;
};

#endif
