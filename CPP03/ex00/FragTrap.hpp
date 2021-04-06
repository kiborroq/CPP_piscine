/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:52:07 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 13:57:50 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "string"
# include "iostream"

class FragTrap
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
		int			randomAttackDamage;
		int			hitWithArmor;
		int			maxHitWithArmor;

		const static std::string randomAttacks[5];
		const static int randomDameges[5];

		void printAttackInfo(std::string const & target, std::string const & attack, unsigned int damage);
		void printMyStatus(void);
		void renewHitWithArmor(void);

	public:
		FragTrap(std::string const & n);
		~FragTrap(void);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void vaulthunter_dot_exe(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;
		void setName(std::string n);
		int getHit(void) const;
		int getRandomDamage(void);
		int getRangedDamage(void);
		int getMeleeDamage(void);
};

std::ostream & operator<<(std::ostream & out, FragTrap const & i);

#endif
