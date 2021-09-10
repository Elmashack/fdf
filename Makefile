# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nluya <nluya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/05 15:08:33 by nluya             #+#    #+#              #
#    Updated: 2021/09/10 13:49:49 by nluya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FRAMEWORKS = -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror  

SRC = design.c dop_func.c main.c read_map.c

OBJ = $(SRC:%.c = %.0)

LIB = libft/libft.a

MLX = minilibx_macos/libmlx.a

HEADER = fdf.h


all: $(NAME)
 
$(NAME): mlx lib
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB) $(MLX) $(FRAMEWORKS)

lib:
	@make -C libft/

mlx:
	@make -C minilibx_macos/

clean:
	@make -C minilibx_macos/ clean
	@make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re