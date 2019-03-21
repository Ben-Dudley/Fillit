/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:11:39 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/10 18:39:32 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_tetris(t_tetris *tetris, unsigned short *map)
{
	short			row;

	row = -1;
	while (++row < tetris->height)
	{
		if (((0b1111000000000000 & (tetris->value << row * 4))
		>> tetris->x) & map[tetris->y + row])
			return (0);
	}
	return (1);
}

void			shape(t_tetris *tetris, unsigned short *map)
{
	short			row;

	row = -1;
	while (++row < tetris->height)
	{
		map[tetris->y + row] = map[tetris->y + row] ^
			(((0b1111000000000000 & (tetris->value << row * 4)) >>
		tetris->x));
	}
}

int				solution(t_tetris *tetris,
		unsigned short size_map, unsigned short *map)
{
	int visited;

	visited = 0;
	if (tetris->letter == '\0')
		return (1);
	tetris->y = (tetris->last != NULL) ? (tetris->last->y) : 0;
	while (tetris->y + tetris->height <= size_map)
	{
		tetris->x = (tetris->last != NULL && visited == 0)
			? (tetris->last->x + 1) : 0;
		visited = 1;
		while (tetris->x + tetris->width <= size_map)
		{
			if (check_tetris(tetris, map))
			{
				shape(tetris, map);
				if (solution(tetris + 1, size_map, map))
					return (1);
				shape(tetris, map);
			}
			tetris->x++;
		}
		tetris->y++;
	}
	return (0);
}

unsigned short	find_smallest_square(t_tetris *tetris,
			int tetris_count)
{
	unsigned short	map[MAX_SIZE_MAP + 1];
	unsigned short	size_map;

	size_map = 2;
	while (size_map * size_map < tetris_count * 4)
		size_map++;
	ft_bzero(map, (MAX_SIZE_MAP + 1) * sizeof(unsigned short));
	while ((solution(tetris, size_map, map)) == 0)
	{
		ft_bzero(map, (MAX_SIZE_MAP + 1) * sizeof(unsigned short));
		size_map++;
	}
	return (size_map);
}
