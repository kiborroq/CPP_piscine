/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:47:08 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 19:04:08 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
	private:
		int					count;
		const static int	maxCount = 50;
		ISpaceMarine		*squad[maxCount];

		void freeSquad(void);
		int isInSquard(ISpaceMarine *sm);

	public:
		Squad(void);
		Squad(Squad const & s);
		~Squad(void);

		Squad & operator=(Squad const & s);

		virtual ISpaceMarine *getUnit(int i) const;
		virtual int push(ISpaceMarine *sm);
		virtual int getCount(void) const;
};

#endif
