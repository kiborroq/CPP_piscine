/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:03:24 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 19:29:03 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		int					count;
		const static int	maxCount = 4;
		AMateria			*learnedMaterias[maxCount];

		void freeLearnedMaterias(void);

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & ms);
		~MateriaSource(void);

		MateriaSource & operator=(MateriaSource const & ms);

		virtual void learnMateria(AMateria *m);
		virtual AMateria *createMateria(std::string const & type);

		int getCount(void) const;
		AMateria *getUnit(int i) const;
};

#endif
