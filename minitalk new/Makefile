LIBFT = libft
LIBA = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


SRCA = server.c
SRCB = client.c

all: lib sc

lib:
	@$(MAKE) -C libft

sc: lib
	$(CC)  $(CFLAGS) $(SRCA) $(LIBFT)/$(LIBA) -o server
	$(CC)  $(CFLAGS) $(SRCB) $(LIBFT)/$(LIBA) -o client

clean:
	$(RM)  $(LIBA)
	make -C $(LIBFT) fclean

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) server
	$(RM) client

re:		fclean all

.PHONY : all clean fclean re
