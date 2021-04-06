/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:50:22 by kiborroq          #+#    #+#             */
/*   Updated: 2021/04/05 00:13:53 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include "stack"
# include "iterator"

template <typename T>
class mutantstack : public std::stack<T>
{
	public:
		mutantstack(void) : std::stack<T>() { }
		mutantstack(unsigned int size) : std::stack<T>(size) { }
		mutantstack(mutantstack const & ms) : std::stack<T>(ms) { }
		~mutantstack(void) { }

		mutantstack & operator=(mutantstack const & ms) { this->c = ms.c; return (*this); }

		class iterator : public std::iterator<std::input_iterator_tag, T>
		{
			private:
				T *p;

			public:
				iterator(T *p) : p(p) { }
				iterator(iterator const & it) : p(it.p) { }
				~iterator(void) { }

				bool operator==(iterator const & it) const { return (p == it.p); }
				bool operator!=(iterator const & it) const { return (p != it.p); }

				T & operator*(void) const { return (*p); }

				iterator & operator++(void) { ++p; return (*this); }
				iterator operator++(int) { iterator tmp(p); ++p; return (tmp); }
				iterator & operator--(void) { --p; return (*this); }
				iterator operator--(int) { iterator tmp(p); --p; return (tmp); }
		};

		iterator begin(void) { return ( iterator(&this->top() - this->size() + 1)); }
		iterator end(void) { return ( iterator(&this->top() + 1)); }
};

#endif
