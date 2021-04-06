/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:36:51 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/18 20:22:02 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include "string"

class AWeapon
{
	protected:
		std::string	name;
		int			apCost;
		int			damage;

		AWeapon(void);

	public:
		AWeapon(std::string const & n, int apc, int d);
		AWeapon(AWeapon const & a);
		virtual ~AWeapon(void);

		AWeapon & operator=(AWeapon const & a);

		std::string getName(void) const;
		int getAPCost(void) const;
		int getDamage(void) const;

		virtual void attack(void) const = 0;
};

#endif
