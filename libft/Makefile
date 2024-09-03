# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2024/08/28 12:31:53 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
MAKE_SILENT = make --no-print-directory

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
	ft_striteri.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_strncmp.c ft_strjoin.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	ft_strcmp.c 

GNL_SRCS =	gnl/get_next_line_utils.c gnl/get_next_line.c \

OBJS = $(SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $?

gnl/%.o: gnl/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(PRINTF_LIB)
	@ar x $(PRINTF_LIB)
	@ar rcs $@ $(OBJS) $(GNL_OBJS) *.o
	@$(RM) *.o
	@echo "$(NAME) created"

$(PRINTF_LIB):
	@$(MAKE_SILENT) -C $(PRINTF_DIR)

clean:
	@$(RM) $(OBJS) $(GNL_OBJS)
	@$(MAKE_SILENT) -C $(PRINTF_DIR) clean
	@echo "Libft object files removed"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE_SILENT) -C $(PRINTF_DIR) fclean
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re