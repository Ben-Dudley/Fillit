/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:08:56 by jgoyette          #+#    #+#             */
/*   Updated: 2019/03/09 20:39:09 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	get_width(unsigned short value)
{
	unsigned short	width;
	int				i;

	width = 1;
	i = 0;
	while (i < 3)
	{
		if (value & (0b100010001000100 >> (1 * i)))
			width += 1;
		else
			break ;
		i += 1;
	}
	return (width);
}

unsigned short	get_height(unsigned short value)
{
	unsigned short	height;
	int				i;

	height = 1;
	i = 0;
	while (i < 3)
	{
		if (value & (0b111100000000 >> (4 * i)))
			height += 1;
		else
			break ;
		i += 1;
	}
	return (height);
}

unsigned short	get_value(const char *str)
{
	unsigned short value;

	value = 0;
	while (*str)
	{
		if (*str == '#' || *str == '.')
		{
			value = value << 1;
			if (*str == '#')
				value = value | 1;
		}
		str += 1;
	}
	while (!(value & 0b1000100010001000))
		value = value << 1;
	while (!(value & 0b1111000000000000))
		value = value << 4;
	return (value);
}

t_tetris		init_tetris(const char *str, char letter)
{
	t_tetris	tetris;

	tetris.x = 0;
	tetris.y = 0;
	tetris.letter = letter;
	tetris.value = get_value(str);
	tetris.width = get_width(tetris.value);
	tetris.height = get_height(tetris.value);
	return (tetris);
}
