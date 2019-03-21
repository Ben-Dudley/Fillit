# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 16:03:19 by jgoyette          #+#    #+#              #
#    Updated: 2018/12/11 14:40:54 by jgoyette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
	   ft_itoa.c ft_lstadd.c ft_lstaddend.c ft_lstdel.c ft_lstdelone.c \
	   ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c \
	   ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memdup.c \
	   ft_memmove.c ft_memrcpy.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	   ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	   ft_putstr_fd.c ft_strarr_del.c ft_strcat.c ft_strchr.c ft_strclr.c \
	   ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	   ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	   ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	   ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnjoin.c ft_strnstr.c \
	   ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	   ft_tolower.c ft_toupper.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
INCLUDES = .

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

.o: .c $(INCLUDES)/libft.h
	gcc $(CFLAGS) -c $? -o $@ -I$(INCLUDES)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
