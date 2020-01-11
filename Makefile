# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 11:58:18 by gmachado          #+#    #+#              #
#    Updated: 2020/01/09 15:06:55 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

HEADER = \
	-I ./includes/ft_ls.h

ARCHIVE = \
	-L includes/libft -l ft \
	-L includes/ft_printf -l ftprintf \

CFLAGS = -g

SRCS = \
	./srcs/ft_ls.c \
	./srcs/diver.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@ echo Compiling...
	@ make -C includes/libft
	@ make -C includes/ft_printf
	@ gcc $(CFLAGS) -o $(NAME) $(SRCS) $(ARCHIVE) -fsanitize=address
	@ echo Finished compiling! Run with ./ft_ls (flags/directories)

clean:
	@ make -C ./includes/libft clean
	@ make -C ./includes/ft_printf clean
	@ rm -f $(OFILES)

fclean:
	@ make -C ./includes/libft fclean
	@ make -C ./includes/ft_printf fclean
	@ rm -f $(NAME)

re: fclean all