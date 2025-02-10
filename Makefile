CLIENT = client
SERVER = server
CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJSV = $(SRC_SERVER:.c=.o)
OBJCT = $(SRC_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)
	
$(SERVER) :
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(SERVER)

$(CLIENT) :
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(CLIENT)

clean:
	rm -f $(OBJSV)
	rm -f $(OBJCT)
fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
