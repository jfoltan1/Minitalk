# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 14:17:11 by jfoltan           #+#    #+#              #
#    Updated: 2023/03/07 12:50:05 by jfoltan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS 	= -Werror -Wall -Wextra
RM		= rm -f

SRCS	=	ft_printf.c\
			format_%.c\
			format_d,i.c\
			format_p.c\
			format_s.c\
			format_u.c\
			format_X,x.c\

OBJS	= $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
