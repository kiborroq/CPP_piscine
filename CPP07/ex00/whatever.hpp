/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:40:19 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/26 22:46:44 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
T const & max(T const & x, T const & y)
{
	if (x > y)
		return (x);
	return (y);
}

template <typename T>
T const & min(T const & x, T const & y)
{
	if (x < y)
		return (x);
	return (y);
}

template <typename T>
void swap(T & x, T & y)
{
	T tmp = x;
	x = y;
	y = tmp;
}


#endif
