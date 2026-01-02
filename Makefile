# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 14:00:36 by fekandle          #+#    #+#              #
#    Updated: 2026/01/02 20:58:28 by fekandle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswab.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_overflow.c list_prep.c main.c  ps_helper.c sort.c stack_operations.c validation.c   moveplusprint1.c moveplusprint2.c nodes.c
OBJ = $(SRC:.c=.o)
LIBFT = ./Libft-v2
LIBFT_MAKE = make -C $(LIBFT)
PRINTF = ./PrintF-v2
PRINTF_MAKE = make -C $(PRINTF)
EXEC = test

all: $(EXEC)

$(EXEC): $(OBJ) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a -o $(EXEC)

$(LIBFT)/libft.a:
		$(LIBFT_MAKE)

$(PRINTF)/libftprintf.a:
	$(PRINTF_MAKE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -f $(EXEC)
	$(LIBFT_MAKE) fclean

re: fclean all
