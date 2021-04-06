/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:10:00 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/27 16:41:07 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "stdexcept"
# include "algorithm"
# include "iterator" 

class notFoundException : public std::exception
{
	public:
		virtual const char *what(void) const throw() { return ("Number not found!"); }
		
};

template <typename T>
typename T::iterator easyfind(T & container, int num)
{
	typename T::iterator occurrence;
	occurrence = std::find(container.begin(), container.end(), num);
	if (occurrence == container.end())
		throw notFoundException();
	return (occurrence);
}

#endif
