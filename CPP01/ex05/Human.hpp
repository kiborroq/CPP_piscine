/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:58:38 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:01:20 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "string"
# include "Brain.hpp"

class Human
{
	private:
		std::string name;
		const Brain *myBrain;

	public:
		Human(std::string name = "unknown");
		~Human(void);

		std::string identify(void) const;
		void printMessege(std::string messege) const;
		std::string toString(void) const;

		const Brain &getBrain(void) const;
		std::string getName(void) const;
};

#endif
