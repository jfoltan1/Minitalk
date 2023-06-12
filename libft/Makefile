# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 13:08:25 by jfoltan           #+#    #+#              #
#    Updated: 2022/12/13 13:08:25 by jfoltan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_isprint.c ft_putchar_fd.c ft_putnbr_fd.c\
ft_strlcat.c ft_atoi.c ft_itoa.c ft_strmapi.c ft_strteri.c ft_putstr_fd.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_strlen.c ft_strjoin.c ft_putendl_fd.c \
ft_toupper.c ft_calloc.c ft_memchr.c ft_substr.c ft_strtrim.c ft_split.c \
ft_isalnum.c ft_memcmp.c ft_strncmp.c ft_isalpha.c ft_memcpy.c \
ft_strchr.c ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_strreverse.c \

SRCSB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
$(SRCS)

OBJS = ${SRCS:.c=.o}
OBJSB = $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))
CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus: $(OBJECTS_BONUS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_BONUS_PREFIXED)

.PHONY : all clean fclean re
