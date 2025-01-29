# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:26:36 by eedwards          #+#    #+#              #
#    Updated: 2025/01/29 13:43:26 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CC = cc -g
RM = rm -rf
CFLAGS = -I./libft/incl -I./incl -Wall -Werror -Wextra
LFLAGS = -L./libft -lft
LIBFT = libft
LIBFTA = libft.a
MAKE_SILENT = make --no-print-directory

C_SRC = src/client.c
S_SRC = src/server.c

C_OBJS = $(patsubst src/%.c,obj/%.o,$(C_SRC))
S_OBJS = $(patsubst src/%.c,obj/%.o,$(S_SRC))

all: $(LIBFT)/$(LIBFTA) $(CLIENT) $(SERVER)

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/$(LIBFTA):
	@$(MAKE_SILENT) -C $(LIBFT)

$(CLIENT): $(C_OBJS)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(C_OBJS) $(LFLAGS)
	@echo "$(CLIENT) created"

$(SERVER): $(S_OBJS)
	@$(CC) $(CFLAGS) -o $(SERVER) $(S_OBJS) $(LFLAGS)
	@echo "$(SERVER) created"

clean:
	@$(MAKE_SILENT) -C $(LIBFT) clean
	@$(RM) obj
	@echo "minitalk object files removed"
	

fclean: clean
	@$(MAKE_SILENT) -C $(LIBFT) fclean
	@$(RM) $(CLIENT)
	@$(RM) $(SERVER)
	@echo "$(CLIENT) and $(SERVER) removed"

re: fclean all

.PHONY: all clean fclean re bonus
