/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:41:09 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/19 23:00:06 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "string"
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string		type;
		unsigned int	xp;

		AMateria(void);

	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & m);
		virtual ~AMateria(void);

		AMateria & operator=(AMateria const & m);

		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter & target);

		std::string const & getType(void) const;
		unsigned int getXP(void) const;
};

#endif
