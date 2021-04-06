/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:32:42 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/19 23:00:33 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "string"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string			name;
		int					count;
		const static int	maxCount = 4;
		AMateria			*inventory[maxCount];

		Character(void);

		void freeInventory(void);

	public:
		Character(std::string name);
		Character(Character const & c);
		~Character(void);

		Character & operator=(Character const & c);

		virtual std::string const & getName(void) const;
		virtual void equip(AMateria * m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter & target);

		int getCount(void) const;
		AMateria *getUnit(int idx) const;
};

#endif
