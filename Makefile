# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdudley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 17:59:10 by bdudley           #+#    #+#              #
#    Updated: 2019/03/09 15:42:20 by jgoyette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./fillit

I = gcc -Wall -Wextra -Werror -c
I_2 = gcc $(O_LIBFT) $(O_FILLIT) -o $(NAME)

C_LIBFT = libft/ft_memset.c libft/ft_bzero.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strlen.c
C_FILLIT = parse_input.c init.c print.c main.c solution.c

O_LIBFT = $(C_LIBFT:.c=.o)
O_FILLIT = $(C_FILLIT:.c=.o)

all: $(NAME)

$(O_LIBFT) = %.o : fillit.h
$(O_FILLIT) = %.o : fillit.h

$(NAME): $(O_LIBFT) $(O_FILLIT)
	$(I) $(C_LIBFT) $(C_LIBFT)
	$(I_2)

clean:
	rm -f $(O_LIBFT) $(O_FILLIT)

fclean: clean
	rm -f $(NAME)

re: fclean all
