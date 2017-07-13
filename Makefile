# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 15:29:40 by tle-meur          #+#    #+#              #
#    Updated: 2016/02/09 19:36:04 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	filler

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c init.c algo.c utilities.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			@gcc $(FLAGS) -o $@ -c $<

$(NAME)	:	$(OBJS)
			@make -C libft/ simple
			@echo "libft.a created"
			@gcc $(FLAGS) -o $@ $^ -L libft/ -lft
			@echo "$(NAME) created"
clean	:
			@rm -f $(OBJS)
			@echo "objects deleted"

fclean	:	clean
			@rm -f $(NAME) libft/libft.a
			@echo "$(NAME) libft.a deleted"

re		:	fclean $(NAME)

simple	:	re
			@rm -f $(OBJS)
			@echo "objects deleted"

.PHONY	:	all clean fclean re simple
