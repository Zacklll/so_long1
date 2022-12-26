# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 14:37:56 by zael-wad          #+#    #+#              #
#    Updated: 2022/12/26 11:16:50 by zael-wad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME=  so_long.a
SRC =  so_long.c get_next_line.c get_next_line_utils.c hooks.c player_position.c moves.c\
		ft_printf.c ft_split.c funcs1.c funcs2.c ft_itoa.c ft_check.c check_map.c\
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all