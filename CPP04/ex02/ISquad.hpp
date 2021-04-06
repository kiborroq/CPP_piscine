/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:29:51 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/19 10:36:27 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{
	public:
		virtual ~ISquad(void) {}
		virtual int getCount(void) const = 0;
		virtual ISpaceMarine *getUnit(int) const = 0;
		virtual int push(ISpaceMarine *sm) = 0;
};

#endif
