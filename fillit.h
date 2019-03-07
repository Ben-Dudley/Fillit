/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:08:17 by bdudley           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/07 18:27:06 by bdudley          ###   ########.fr       */
=======
/*   Updated: 2019/03/07 17:21:07 by jgoyette         ###   ########.fr       */
>>>>>>> 33cb6eac0378f805f10bcfc6ca60e4e15be4b81c
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 21
# define MAX_TETRIMINOS 26

typedef struct	s_tetriminos
{
	char letter;
	unsigned short value;
	unsigned short width;
	unsigned short height;
	unsigned short x;
	unsigned short y;
} t_tetriminos;

t_tetriminos	init_tetriminos(const char *str, char letter);
<<<<<<< HEAD
void			solution_help(t_tetriminos tetriminos[27], int number);
void			print(t_tetriminos tetriminos[27], unsigned short map[17], unsigned short size_map, int number);
=======
void			solution_help(t_tetriminos tetriminos[27]);
void			print(t_tetriminos tetriminos[27], unsigned short map[17]);
int				read_tetriminos(t_tetriminos *tetriminos, int fd);
>>>>>>> 33cb6eac0378f805f10bcfc6ca60e4e15be4b81c

#endif
