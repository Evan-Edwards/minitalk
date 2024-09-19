# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:26:36 by eedwards          #+#    #+#              #
#    Updated: 2024/09/05 17:53:36 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CC = cc -g
RM = rm -rf
CFLAGS = -I./libft/incl -Wall -Werror -Wextra
LFLAGS = -L./libft -lft
LIBFT = libft
LIBFTA = libft.a

C_SRC = client.c
S_SRC = server.c

C_OBJS = $(C_SRC:.c=.o)
S_OBJS = $(S_SRC:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(C_OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(C_OBJS) $(LFLAGS)

$(SERVER): $(S_OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(S_OBJS) $(LFLAGS)

clean:
	$(RM) $(C_OBJS)
	$(RM) $(S_OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(CLIENT)
	$(RM) $(SERVER)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus
