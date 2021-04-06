/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:52:07 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 00:04:28 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "string"
# include "iostream"

class ScavTrap
{
	private:
		std::string	name;

		int			hit;
		int			maxHit;
		int			energy;
		int			maxEnergy;
		int			level;
		int			meleeAttackDamage;
		int			rangedAttackDamage;
		int			armorAttackDamage;
		int			hitWithArmor;
		int			maxHitWithArmor;

		const static std::string randomChallengs[5];

		void printAttackInfo(std::string const & target, std::string const & attack, unsigned int damage);
		void printMyStatus(void);
		void renewHitWithArmor(void);

	public:
		ScavTrap(std::string const & n);
		~ScavTrap(void);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer(void);

		std::string getName(void) const;
		void setName(std::string n);
		int getHit(void) const;
		int getRangedDamage(void);
		int getMeleeDamage(void);
};

std::ostream & operator<<(std::ostream & out, ScavTrap const & i);

#endif
