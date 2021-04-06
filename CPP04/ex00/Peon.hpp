/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:59:19 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 23:22:07 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "iostream"
# include "string"
# include "Victim.hpp"

class Peon : public Victim
{
	private:
		Peon(void);

	public:
		Peon(std::string const & n);
		Peon(Peon const & p);
		virtual ~Peon(void);

		Peon & operator=(Peon const & p);

		virtual void getPolymorphed(void) const;
};

#endif
