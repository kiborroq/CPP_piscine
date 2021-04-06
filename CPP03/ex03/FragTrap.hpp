/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:52:07 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 00:19:41 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "string"
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		int	randomAttackDamage;

		const static std::string randomAttacks[5];
		const static int randomDameges[5];

	public:
		FragTrap(std::string const & n);
		~FragTrap(void);

		void vaulthunter_dot_exe(std::string const & target);

		int getRandomDamage(void);
};

#endif
