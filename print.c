/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:52:25 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/07 17:29:58 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print(t_tetriminos tetriminos[27], unsigned short map[17], unsigned short size_map, int number)
{
	unsigned short x;
	unsigned short y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (y < size_map)
	{
		x = 0;
		while (x < size_map)
		{
			i = -1;
			while (++i < number)
			{
				if (tetriminos[i].x == x && tetriminos[i].y == y)
				{
					ft_putchar(tetriminos[i].letter);
					break;
				}
			}
			x++;
		}
		y++;
	}
}
