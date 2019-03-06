/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:08:17 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/06 14:57:34 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

//# include "libft/libft.h"
# include <fcntl.h>
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
void			solution_help(t_tetriminos tetriminos[27]);
void			print(t_tetriminos tetriminos[27], unsigned short map[17]);

#endif
