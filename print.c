/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:52:25 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/12 20:31:25 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_str(unsigned short size_map, char *str)
{
	int i;

	i = 0;
	str[size_map * (size_map + 1)] = '\0';
	while (++i < size_map * (size_map + 1) + 1)
	{
		if (i % (size_map + 1) == 0)
			str[i - 1] = '\n';
		else
			str[i - 1] = '.';
	}
}

void	print(t_tetris *tetris,
		unsigned short size_map, int tetris_count)
{
	unsigned short	x;
	unsigned short	y;
	char			str[size_map * (size_map + 1) + 1];
	int				i;

	put_str(size_map, str);
	i = 0;
	while (i < tetris_count)
	{
		y = 0;
		while (y < tetris[i].height)
		{
			x = 0;
			while (x < tetris[i].width)
			{
				if ((tetris[i].value >> (16 - x - y * 4 - 1)) & 1)
					str[(size_map + 1) * (tetris[i].y + y) +
						tetris[i].x + x] = tetris[i].letter;
				x++;
			}
			y++;
		}
		i++;
	}
	ft_putstr(str);
}
