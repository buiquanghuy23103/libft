# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 11:39:05 by hbui              #+#    #+#              #
#    Updated: 2022/03/30 22:31:24 by hbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra
HEADER_FLAGS = -I .

# Logs
TEST_LOG = test_log
PRINTF_TEST_LOG = printf_test_log

SRCS = ft_abs.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
ft_numlen.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_lst_push_back.c ft_lst_len.c ft_lst_get.c\
ft_tabndel.c ft_tabdel.c ft_tablen.c ft_set.c \
ft_open_close_file.c ft_setbit.c ft_getbit.c ft_swap.c \
ft_trailing0bit_count.c ft_max1bits.c get_next_line.c

# Add ft_printf
PRINTF_CONVS = d_conv.c c_conv.c s_conv.c p_conv.c o_conv.c u_conv.c x_conv.c \
xx_conv.c perc_conv.c f_conv.c b_conv.c
PRINTF_HELPERS = getinfo.c builder.c build_integer.c build_float.c build_color.c
SRCS += $(PRINTF_CONVS:%=printf_conversions/%)
SRCS += $(PRINTF_HELPERS:%=printf_helpers/%)
SRCS += ft_printf.c

OBJS = $(SRCS:%.c=%.o)

.PHONY = all clean fclean re check norm check_base

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

$(OBJS): %.o : %.c
	gcc $(CFLAGS) $(HEADER_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf a.out*
	rm -rf $(TEST_LOG)
	rm -rf $(PRINTF_TEST_LOG)

fclean: clean
	rm -f $(NAME)

re: fclean all

check: all norm run_tests

run_tests: update_tests 
	@make -sC tests/libft | tee $(TEST_LOG) | grep -v -e ':PASS'
	@cp libft.a libftprintf.a
	@make -sC tests_moulitests ft_printf | tee $(PRINTF_TEST_LOG) | grep -v -e 'Ok' | grep '>>>>'
	@rm -rf libftprintf.a

update_tests: tests tests_moulitests
	@git -C tests pull > /dev/null
	@git -C tests_moulitests pull > /dev/null

tests:
	@git clone https://github.com/buiquanghuy23103/Unity.git tests > /dev/null
	@echo "Cloned https://github.com/buiquanghuy23103/Unity.git"

tests_moulitests:
	@git clone https://github.com/buiquanghuy23103/moulitest.git tests_moulitests
	@echo "Cloned https://github.com/buiquanghuy23103/moulitest.git"
	echo "FT_PRINTF_PATH = $(shell pwd)" > tests_moulitests/config.ini

norm:
	@printf "\e[1;34m===NORM===\e[0m\n"
	@find . -name '*.c' -o -name '*.h' | grep -v -e "./tests*" -e "test*" | xargs norminette | grep "Error" || printf "\e[1;32mNORM ok\e[0;0m\n"
