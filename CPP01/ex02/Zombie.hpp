/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:44:05 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:05:06 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "string"

class Zombie
{
	private:
		std::string name;
		std::string type;

	public:
		Zombie(std::string name = "unknown", std::string type = "standart");
		~Zombie(void);

		void announce(void) const;
		void printMessege(std::string messege) const;
		std::string toString(void) const;

		void setName(std::string name);
		void setType(std::string type);
		std::string getName(void) const;
		std::string getType(void) const;
};

#endif
