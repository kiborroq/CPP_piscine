/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:59:39 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 22:29:34 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "cstring"
# include "unistd.h"

template <typename T>
class Array
{
	private:
		unsigned int	n;
		T				*arr;

	public:
		Array(void) : n(0), arr(new T[1]) { std::memset(arr, 0, sizeof(T)); }
		Array(unsigned int n) : n(n), arr(new T[n]) { std::memset(arr, 0, sizeof(T) * n); }
		Array(Array const & a) { arr = NULL; *this = a; }
		~Array(void) { delete [] arr; }

		Array & operator=(Array const & a)
		{
			delete [] arr;
			n = a.size();
			arr = new T[!n ? 1 : n];
			for (unsigned int i = 0; i < n; i++)
			   arr[i] = a[i];
			return (*this);
		}

		T & operator[](unsigned int i)
		{
			if (i != 0 && i >= n)
				throw std::exception();
			return (arr[i]);
		}

		const T & operator[](unsigned int i) const
		{
			if (i != 0 && i >= n)
				throw std::exception();
			return (arr[i]);
		}

		unsigned int size(void) const { return (this->n); }
};

#endif
