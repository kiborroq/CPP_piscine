/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:16:35 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 16:09:46 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Converter.hpp"

int main(int argc, char ** argv)
{
	if (argc == 2)
	{
		Converter().display(std::string(argv[1]));
	}
	else
	{
		std::cout << "To few/much arguments!" << std::endl;
	}
	return (0);
}
