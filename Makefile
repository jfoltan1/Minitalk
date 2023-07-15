LIBFT = libft
LIBA = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCA = server.c
SRCB = client.c

all: server client

server: $(SRCA) $(LIBFT)/$(LIBA)
	$(CC) $(CFLAGS) $(SRCA) $(LIBFT)/$(LIBA) -o server

client: $(SRCB) $(LIBFT)/$(LIBA)
	$(CC) $(CFLAGS) $(SRCB) $(LIBFT)/$(LIBA) -o client

$(LIBFT)/$(LIBA):
	@$(MAKE) -C $(LIBFT)

clean:
	make -C $(LIBFT) clean

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) server
	$(RM) client
re: fclean all

.PHONY: all clean fclean re
