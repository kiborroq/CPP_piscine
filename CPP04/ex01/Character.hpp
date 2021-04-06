/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:09:03 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/18 22:53:43 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "string"
# include "iostream"
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	private:
		std::string	name;
		int			apoints;
		AWeapon		*weapon;

		Character(void);

	public:
		Character(std::string const & n);
		Character(Character const & c);
		~Character(void);

		Character & operator=(Character const & c);

		void recoverAP(void);
		void equip(AWeapon *w);
		void attack(Enemy *e);

		std::string getName(void) const;
		int getAP(void) const;
		const AWeapon *getWeapon(void) const;
};

std::ostream & operator<<(std::ostream & out, Character const & c);

#endif
