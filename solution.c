/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:11:39 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/09 20:36:59 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				check_tetris(t_tetris *tetris, unsigned short map[17])
{
	short			row;

	row = -1;
	while (++row < tetris->height)
		if (((0b1111000000000000 & (tetris->value << row * 4))
					>> tetris->x) & map[tetris->y + row])
			return (0);
	return (1);
}

void			shape(t_tetris *tetris, unsigned short *map[17])
{
	short			row;

	row = -1;
	while (++row < tetris->height)
		(*map)[tetris->y + row] = (*map)[tetris->y + row] ^
			(((0b1111000000000000 & (tetris->value << row * 4)) >>
			tetris->x) & (*map)[tetris->y + row]);
}

int				solution(t_tetris tetris[27],
		unsigned short size_map, unsigned short map[17])
{
	if (tetris->letter == '\0')
		return (1);
	tetris->y = 0;
	while (tetris->y + tetris->height <= size_map)
	{
		tetris->x = 0;
		while (tetris->x + tetris->width <= size_map)
		{
			if (check_tetris(tetris, map))
			{
				shape(tetris, &map);
				if (solution(tetris + 1, size_map, map))
					return (1);
				else
					shape(tetris, &map);
			}
			tetris->x++;
		}
		tetris->y++;
	}
	tetris->x = 0;
	tetris->y = 0;
	return (0);
}

unsigned short	find_smallest_square(t_tetris tetris[27], int tetris_count)
{
	unsigned short	map[17];
	unsigned short	size_map;

	size_map = 2;
	while (size_map * size_map < tetris_count * 4)
		size_map++;
	ft_bzero(map, 17 * sizeof(unsigned short));
	while ((solution(tetris, size_map, map)) == 0)
	{
		ft_bzero(map, 17 * sizeof(unsigned short));
		size_map++;
	}
	return (size_map);
}
