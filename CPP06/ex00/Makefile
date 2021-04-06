# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 14:01:28 by kiborroq          #+#    #+#              #
#    Updated: 2021/03/24 20:42:22 by kiborroq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		converter

SRCS = 		main.cpp \
			Converter.cpp
			
OBJS = 		$(SRCS:.cpp=.o)

CC = 		clang++
FLAGS = 	-Wall -Wextra -Werror

.cpp.o:
			$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			${CC} $(FLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			rm -f *.o

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re .cpp.o