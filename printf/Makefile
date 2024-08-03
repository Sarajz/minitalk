# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 16:36:20 by sarajime          #+#    #+#              #
#    Updated: 2023/12/28 17:07:37 by sarajime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
FILES = ft_printf.c ft_unsigned.c ft_words.c ft_numbers.c
OBJETS = $(FILES:.c=.o)

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

$(NAME): $(OBJETS)
	@ar rcs $(NAME) $(OBJETS)
	@echo "$(COLOUR_GREEN)Librería ready$(COLOUR_END)"
	
%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@

all: $(NAME)

clean:
	@rm -f *.o
	@echo "$(COLOUR_BLUE)Casa limpia$(COLOUR_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOUR_RED)FCasa limpia$(COLOUR_END)"

re: fclean all

.PHONY: all fclean clean re
