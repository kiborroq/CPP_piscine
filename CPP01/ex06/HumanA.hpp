/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:58:38 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 19:59:39 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "string"
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon & waepon;

	public:
		HumanA(std::string name, Weapon & weapon);
		~HumanA(void);

		void attack(void) const;

		void printMessege(std::string messege) const;
		std::string toString(void) const;
};

#endif
