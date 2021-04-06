/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:58:51 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:01:01 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "string"

class Brain
{
	private:
		int			iq;
		int			degreeOfTaste;
		std::string	ownerName;

	public:
		Brain(std::string ownerName = "unknown", int iq = 0, int degreeOfTaste = 0);
		~Brain(void);

		std::string identify(void) const;
		void printMessege(std::string messege) const;
		std::string toString(void) const;
};

#endif
