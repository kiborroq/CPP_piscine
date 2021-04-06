/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:57:54 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 23:21:59 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include "string"
# include "iostream"

class Victim
{
	protected:
		std::string name;

		Victim(void);

	public:
		Victim(std::string const & n);
		Victim(Victim const & v);
		virtual ~Victim(void);

		Victim & operator=(Victim const & v);

		virtual void getPolymorphed(void) const;

		std::string getName(void) const;
};

std::ostream & operator<<(std::ostream & out, Victim const & v);

#endif
