# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idelemen <idelemen@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 14:31:29 by idelemen          #+#    #+#              #
#    Updated: 2024/04/29 12:52:29 by idelemen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

CFILES = commands_a.c \
			commands_b.c \
			sort.c \
			five_sort.c \
			utils.c \
			push_swap.c \
			radix.c

			
OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(LIBFT)


$(LIBFT):
	@$(MAKE) -C libft
clean:
		@$(MAKE) -C libft clean
		@rm -f  $(OBJS)

fclean: clean
		@$(MAKE) -C libft fclean
		@rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
