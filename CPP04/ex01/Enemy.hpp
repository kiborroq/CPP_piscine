/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:33:15 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/18 21:00:14 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "string"

class Enemy
{
	protected:
		int			hp;
		std::string	type;

		Enemy(void);

	public:
		Enemy(int hp, std::string const & t);
		Enemy(Enemy const & e);
		virtual ~Enemy(void);

		Enemy & operator=(Enemy const & e);

		virtual void takeDamage(int damage);

		std::string getType(void) const;
		int getHP(void) const;
};

#endif
