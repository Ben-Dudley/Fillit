/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:08:56 by jgoyette          #+#    #+#             */
/*   Updated: 2019/03/10 18:11:35 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	get_width(unsigned short value)
{
	unsigned short	width;
	int				i;

	width = 1;
	i = 0;
	while (i < 3 && value & (0b100010001000100 >> (1 * i)))
	{
		width += 1;
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
	while (i < 3 && value & (0b111100000000 >> (4 * i)))
	{
		height += 1;
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

t_tetris		*get_last(t_tetris *tetris, t_tetris t, int count)
{
	int idx;

	idx = count - 1;
	while (idx >= 0)
	{
		if (t.value == tetris[idx].value)
			return (&tetris[idx]);
		idx -= 1;
	}
	return (NULL);
}

t_tetris		init_tetris(const char *str, char letter,
							t_tetris *tetris, int count)
{
	t_tetris	t;

	t.x = 0;
	t.y = 0;
	t.letter = letter;
	t.value = get_value(str);
	t.width = get_width(t.value);
	t.height = get_height(t.value);
	t.last = get_last(tetris, t, count);
	return (t);
}
