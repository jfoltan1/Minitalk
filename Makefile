LIBFT = libft
LIBA = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


SRCA = server.c
SRCB = client.c

all: sc clean

libft:
	@make $(LIBFT)
	@cp $(LIBFT)/$(LIBA) .

sc: libft
	$(CC)  $(CFLAGS) $(SRCA) $(LIBFT)/$(LIBA) -o server
	$(CC)  $(CFLAGS) $(SRCB) $(LIBFT)/$(LIBA) -o client

clean:
	$(RM)  $(LIBA)
	make -C $(LIBFT) fclean

fclean: clean
	make -C $(LIBFT) fclean

finish: fclean
	$(RM) server
	$(RM) client

re: fclean all

reall: finish all
