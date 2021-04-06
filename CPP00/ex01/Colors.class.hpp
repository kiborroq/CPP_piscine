/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 02:12:41 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 11:42:00 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_CLASS_HPP
# define COLORS_CLASS_HPP

# include <string>

class Colors
{
    public:
        Colors(void);
        ~Colors(void);

        static std::string red(std::string str);
        static std::string green(std::string str);
        static std::string white(std::string str);
        static std::string blue(std::string str);
        static std::string darkBlue(std::string str);
        static std::string pink(std::string str);
        static std::string yellow(std::string str);
};

#endif
