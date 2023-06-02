# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 21:51:05 by rsoo              #+#    #+#              #
#    Updated: 2023/03/20 21:51:05 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solver
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRCS_DIR = srcs/
SRCS = main.c ft_std.c ft_solvegrid_ver3.c ft_grid.c ft_errorhandling.c
SRCS_CFILES = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(SRCS_CFILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling all files... Creating output file..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
