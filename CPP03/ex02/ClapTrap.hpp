/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:52:07 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 00:14:03 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "string"
# include "iostream"

class ClapTrap
{
	private:
		std::string trap;

	protected:
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

		void printAttackInfo(std::string const & target, std::string const & attack, unsigned int damage);
		void printMyStatus(void);
		void renewHitWithArmor(void);

	public:
		ClapTrap(std::string const & n, std::string const & t,
				int hit, int maxHit, int energy, int maxEnergy,
				int level, int meleeAttackDamage,
				int rangedAttackDamage, int armorAttackDamage);
		~ClapTrap(void);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;
		void setName(std::string n);
		int getHit(void) const;
		int getRangedDamage(void);
		int getMeleeDamage(void);
		std::string getTrap(void) const;
		void setTrap(std::string t);
};

std::ostream & operator<<(std::ostream & out, ClapTrap const & i);

#endif
