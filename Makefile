# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 11:39:05 by hbui              #+#    #+#              #
#    Updated: 2022/03/19 17:33:51 by hbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): base/libft.a gnl/get_next_line.o
	ar -rcs $@ $^

base/libft.a:
	make -sC base

gnl/get_next_line.o:
	gcc -Wall -Werror -Wextra -I base/includes -I gnl -c gnl/get_next_line.c -o gnl/get_next_line.o

clean:
	make -sC base clean
	make -sC gnl clean
	rm -rf a.out*

fclean: clean
	rm -f $(NAME)

re: fclean all

check: norm tests check_libft check_gnl

check_libft:
	@make -sC tests libft_bonus > /dev/null && printf "\e[1;32mLIBFT ok\e[0;0m\n" || printf "\e[1;31mLIBFT fail\[0;0m\n"

check_gnl:
	@make -sC tests gnl > /dev/null && printf "\e[1;32mGET_NEXT_LINE ok\e[0;0m\n" || printf "\e[1;31mGET_NEXT_LINE fail\e[0;0m\n"

tests:
	git clone https://github.com/buiquanghuy23103/moulitest.git tests
	echo "LIBFT_PATH = $(shell pwd)/base" > tests/config.ini
	echo "GET_NEXT_LINE_PATH = $(shell pwd)/gnl" >> tests/config.ini

norm:
	@find . -name '*.c' -name '*.h' | xargs norminette | grep "Error" || printf "\e[1;32mNORM ok\e[0;0m\n"
