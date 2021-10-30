# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 11:39:05 by hbui              #+#    #+#              #
#    Updated: 2021/10/30 19:06:35 by hbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = .
HEADER_DIR = .
BUILD_DIR = ./build

SRCS = $(shell find $(SRCS_DIR) -name '*.c')
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)

.PHONY = clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	gcc -I $(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
