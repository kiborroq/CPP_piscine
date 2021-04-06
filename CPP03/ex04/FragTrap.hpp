/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:52:07 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 18:25:16 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "string"
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
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
