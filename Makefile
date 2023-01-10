# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 14:37:56 by zael-wad          #+#    #+#              #
#    Updated: 2023/01/10 17:58:49 by zael-wad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME=  so_long
SRC =  so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c hooks.c player_position.c so_long_utils.c\
		so_long_utils1.c so_long_utils2.c moves.c ft_printf/ft_printf.c ft_split.c ft_printf/funcs1.c ft_printf/funcs2.c ft_itoa.c\
		ft_printf/ft_check.c check_map.c ft_strrchr.c ft_strncmp.c enemy_move.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all