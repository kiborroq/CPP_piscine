/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 00:18:06 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 17:06:56 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "string"
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	private:
		const static std::string randomKills[3];

		void killAny(ClapTrap & ct);

	public:
		NinjaTrap(std::string const & n);
		~NinjaTrap(void);

		void ninjaShoebox(ClapTrap & ct);
		void ninjaShoebox(FragTrap & ft);
		void ninjaShoebox(ScavTrap & st);
		void ninjaShoebox(NinjaTrap & nt);
};

#endif
