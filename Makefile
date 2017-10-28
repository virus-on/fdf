# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 15:22:42 by vpopovyc          #+#    #+#              #
#    Updated: 2016/11/27 12:12:26 by mpaziuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \
	ft_draw.c \
	ft_3d_transform.c \
	ft_color_init.c \
	ft_tools.c \
	ft_work_with_color.c \
	libft/get_next_line.c \
	ft_func.c \

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -O2
GFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME) $(GFLAGS)

%.o: %.c fdf.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

libft/libft.a:
	make -C libft