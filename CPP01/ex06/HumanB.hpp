/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:58:38 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:15:37 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "string"
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *waepon;

	public:
		HumanB(std::string name);
		~HumanB(void);

		void attack(void) const;

		void setWeapon(Weapon & NewWeapon);

		void printMessege(std::string messege) const;
		std::string toString(void) const;
};

#endif
