#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 13:03:44 by ytailor           #+#    #+#              #
#    Updated: 2014/01/26 17:50:12 by ytailor          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell2

FLAGS = -Wall -Wextra -Werror

SRCS =	main.c					\
		ft_list.c				\
		ft_env.c				\
		ft_change_directory.c	\
		ft_while.c				\
		ft_list_to_tab.c		\
		ft_init.c				\
		ft_run.c				\
		ft_operateur.c			\
		ft_operateur2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	gcc $(FLAGS) $(SRCS) -o $(NAME) libft/libft.a

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
