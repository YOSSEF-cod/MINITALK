CLIENT = client
SERVER = server
CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJSV = $(SRC_SERVER:.c=.o)
OBJCT = $(SRC_CLIENT:.c=.o)

all : $(SERVER) $(CLIENT) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(SERVER) : $(OBJSV) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJSV) $(LIBFT) $(FT_PRINTF) -o $(SERVER)

$(CLIENT) : $(OBJCT) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJCT) $(LIBFT) $(FT_PRINTF) -o $(CLIENT)

clean:
	rm -f $(OBJSV)
	rm -f $(OBJCT)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

