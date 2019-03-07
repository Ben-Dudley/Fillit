/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:52:25 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/07 22:11:40 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print(t_tetriminos tetriminos[27], unsigned short size_map, int number)
{
	unsigned short x;
	unsigned short y;
	char str[size_map*(size_map +1)];
	int i;

	i = 0;
	while (++i < size_map*(size_map+1))
	{
		if  (i % (size_map+1) == 0)
			str[i -1] = '\n';
		else
			str[i -1] = '.';
	}
	i = 0;
	while (i < number)
	{
		y = 0;
		while (y < tetriminos[i].height)
		{
			x = 0;
			while (x < tetriminos[i].width)
			{
				if ((tetriminos[i].value >> (16 - x -y*4 -1)) & 1)
				{
					printf("lolo %d *** %d *** %d *** %d\n", x, tetriminos[i].x, y, tetriminos[i].y);
					str[(size_map + 1)*(tetriminos[i].y + y) + tetriminos[i].x + x] = tetriminos[i].letter;
		
				}
				x++;
			}
			y++;
		}
		i++;
	}
}
