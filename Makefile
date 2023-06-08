LIBFT = libft
PRINTF = ft_printf
LIBA = libft.a
PRIA = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM	= rm -f

SRCA = server.c
SRCB = client.c

all: sc clean

sc: printf libft
				$(CC) $(CFLAGS) $(SRCA) $(PRIA) -o server
				$(CC) $(CFLAGS) $(SRCB) $(LIBA) $(PRIA) - o client

libft:
		@make -C $(LIBFT)
		@cp $(LIBFT)/$(LIBA) .
printf:
		@make -C $(LIBFT)
		@cp $(LIBFT)/$(LIBA) .
clean:
		$(RM) libft.a libftprintf.a
		make -C $(LIBFT) clean
		make -C $(PRINTF) clean
fclean: clean
		make -C $(LIBFT) fclean
		make -C $(PRINTF) fclean
finish: fclean
		$(RM) server client

re: fclean all
reall: finish all
