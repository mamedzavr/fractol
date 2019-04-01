# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 12:11:08 by wqarro-v          #+#    #+#              #
#    Updated: 2019/03/26 16:32:31 by wqarro-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = ./src/*.c
INC = ./inc
LIBFTFOLDER = ./libft
LIBFTINC = -I ./libft -L ./libft -lft
FLAGS = -Wall -Wextra -Werror

MLX = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -framework OpenCL

all: $(NAME)

$(NAME): makelibft
	gcc -g $(FLAGS) $(MLX) $(LIBFTINC) -I $(INC) $(SRC) -o $(NAME)

clean:
	make -C $(LIBFTFOLDER) clean

fclean:
	make -C $(LIBFTFOLDER) fclean
	rm -f $(NAME)

re: fclean all

makelibft:
	$(MAKE) -C $(LIBFTFOLDER)
