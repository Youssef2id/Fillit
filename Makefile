# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 23:02:40 by yidabdes          #+#    #+#              #
#    Updated: 2018/12/07 23:17:33 by yidabdes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra

SRC		= 	libft/*.c\
			fillit.c\
			get_next_line.c\
			map.c\
			print_map_colors.c\
			read.c\
			solve.c\
			valid.c\
			valid_file.c\
			animated_solve.c\
			valid_tetro.c

SRC := $(addprefix srcs/, $(SRC))

.PHONY: all

all: $(NAME)

$(NAME): 	
		@rm -f fillit_colored
		@rm -f fillit_colored.c
		@gcc $(CFLAGS) -c $(SRC)
		@gcc *.o $(CFLAGS) -o $(NAME)
		@echo "\x1b[32m---------- COMPILED SUCCESSFULLY ----------\x1b[0m"

colored: all
		@rm -f fillit.o
		@rm -f fillit
		@gcc $(CFLAGS) -c srcs/fillit_colored.c
		@gcc *.o $(CFLAGS) -o $(NAME)_colored
		@echo "\x1b[32m---------- COLORED  SUCCESSFULLY ----------\x1b[0m"

.PHONY: clean
clean:
	@rm -f *.o
	@rm -f fillit_colored
	@echo "\x1b[32m---------- CLEANED SUCCESSFULLY ----------\x1b[0m"

.PHONY: fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all