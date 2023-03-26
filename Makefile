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

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFILES = main.c ft_std.c ft_solvegrid_ver3.c ft_grid.c ft_errorhandling.c

all: output

output: $(CFILES)
	@echo "Compiling all files... Creating output file..."
	@$(CC) $(CFLAGS) $(CFILES)
