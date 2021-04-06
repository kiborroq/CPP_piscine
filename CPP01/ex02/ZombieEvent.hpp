/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:13:19 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:07:19 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "string"
# include "Zombie.hpp"

class ZombieEvent
{
	private:
		std::string zombieType;

		std::string getRandomName(void) const;

	public:
		ZombieEvent(std::string zombieType = "standart");
		~ZombieEvent(void);

		void setZombieType(std::string zombieType);
		Zombie *newZombie(std::string name) const;
		void randomChump(void) const;
};

#endif
