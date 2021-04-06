/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phony.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:10:47 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:08:20 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONY_CPP
# define PHONY_CPP

# include "string"
# include "sstream"

class Phony
{
	private:
		std::string nickname;
		std::string	color;
		int			age;

	public:
		Phony(std::string nickname, std::string color, int age);
		~Phony();

		std::string toString(void) const;
};

#endif
