CLIENT = client
SERVER = serves
CFLAGS = -Wall -Wextra -Werror 
CC = cc

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC_SERVER = server.c
SRC_CLIENT = client.c ft_atoi.c

OBJSRV = $(SRC_SERVER:.c=.o)
OBJCLT = $(SRC_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT) $(FT_PRINTF)

$(FT_PRINTF): 
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(CLIENT): $(OBJCLT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJCLT) $(FT_PRINTF) -o $(CLIENT)

$(SERVER): $(OBJSRV) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJSRV) $(FT_PRINTF) -o $(SERVER)

clean:
	rm -f $(OBJCLT)
	rm -f $(OBJSRV)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all
