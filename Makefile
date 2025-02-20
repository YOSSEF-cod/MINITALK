CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CFLAGS = -Wall -Wextra -Werror
CC = cc

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a


SRC_SERVER = server.c
SRC_CLIENT = client.c ft_atoi.c
SRC_SERVER_BONUS = server_bonus.c 
SRC_CLIENT_BONUS = client_bonus.c ft_atoi.c

OBJSRV = $(SRC_SERVER:.c=.o)
OBJCLT = $(SRC_CLIENT:.c=.o)

OBJSRV_BS = $(SRC_SERVER_BONUS:.c=.o)
OBJCLT_BS = $(SRC_CLIENT_BONUS:.c=.o)

all: $(SERVER) $(CLIENT) $(FT_PRINTF)

bonus: $(FT_PRINTF) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJCLT_BS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJCLT_BS) $(FT_PRINTF) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJSRV_BS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJSRV_BS) $(FT_PRINTF) -o $(SERVER_BONUS)

$(FT_PRINTF): 
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(CLIENT): $(OBJCLT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJCLT) $(FT_PRINTF) -o $(CLIENT)

$(SERVER): $(OBJSRV) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJSRV) $(FT_PRINTF) -o $(SERVER)

clean:
	rm -f $(OBJCLT) $(OBJSRV)
	rm -f $(OBJSRV_BS) $(OBJCLT_BS)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	rm -f $(CLIENT_BONUS) $(SERVER_BONUS)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all
