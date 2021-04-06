/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 02:16:25 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/08 02:24:44 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.class.hpp"

std::string Colors::green(std::string str)
{
	return
	(
		"\033[1;32m" +
		str +
		"\033[0m"
	);
}
std::string Colors::red(std::string str)
{
	return
	(
		"\033[1;31m" +
		str +
		"\033[0m"
	);
}
std::string Colors::blue(std::string str)
{
	return
	(
		"\033[1;36m" +
		str +
		"\033[0m"
	);
}
std::string Colors::darkBlue(std::string str)
{
	return
	(
		"\033[1;34m" +
		str +
		"\033[0m"
	);
}
std::string Colors::pink(std::string str)
{
	return
	(
		"\033[1;35m" +
		str +
		"\033[0m"
	);
}
std::string Colors::yellow(std::string str)
{
	return
	(
		"\033[1;33m" +
		str +
		"\033[0m"
	);
}
std::string Colors::white(std::string str)
{
	return
	(
		"\033[1;29m" +
		str +
		"\033[0m"
	);
}