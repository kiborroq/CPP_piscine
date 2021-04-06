/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:37:16 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 18:36:48 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include "iostream"
# include "string"
# include "Victim.hpp"

class Sorcerer
{
	private:
		std::string name;
		std::string title;

		Sorcerer(void);

	public:
		Sorcerer(std::string const & n, std::string const & t);
		Sorcerer(Sorcerer const & s);
		~Sorcerer(void);

		Sorcerer & operator=(Sorcerer const & s);

		void polymorph(Victim const & v) const;

		std::string getName(void) const;
		std::string getTitle(void) const;
};

std::ostream & operator<<(std::ostream & out, Sorcerer const & s);

#endif
