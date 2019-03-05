/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:08:17 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/05 22:10:56 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# define BUFF_SIZE 21

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
int				solution(t_tetriminos tetriminos[27], unsigned short size_map, unsigned short map[17], unsigned short number);

#endif
