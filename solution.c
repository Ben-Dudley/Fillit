/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:20:14 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/06 14:57:31 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

//Функция чекающая можем мы вставить фигуру или нет
int		check_tetrimino(t_tetriminos tetrimino, unsigned short size_map, unsigned short map[17])
{
	short row;
	unsigned short tmp;

	row = -1;
	while (++row < 4)
	{
		while (tetrimino.x + tetrimino.width > size_map && tetrimino.y + tetrimino.height <= size_map)
		{
			tetrimino.y += 1;	
			tetrimino.x = 0;
		}
		if (tetrimino.y + tetrimino.height > size_map)
			return (0);
		tmp =(tetrimino.value << 4*row);
		tmp = tmp >> tetrimino.x;
		if (tmp & map[tetrimino.y + row])
		{
			tetrimino.x++;
			row = -1;
		}
	}
	return (1);
}

void	put_shape(t_tetriminos tetrimino, unsigned short map[17])
{
	short row;
	short num;
	unsigned short tmp;

	row = -1;
	while (++row < 4)
	{
		tmp =(tetrimino.value << 4*row);
		tmp = tmp >> tetrimino.x;
		map[tetrimino.y + row] = map[tetrimino.y + row] || tmp;
	}
}

int	solution(t_tetriminos tetriminos[27], unsigned short size_map, unsigned short map[17], unsigned short number)
{
	if (tetriminos->letter == '\0')
		return (1);
	if (check_tetrimino(tetriminos[number], size_map, map))
	{
		put_shape(tetrimino[number], map);
		solution(tetriminos, size_map, map, number + 1);
		return (1);
	}
	else
	{
	printf("False!");
		//0, тогда откатится к предыдущей фигуре, почистить поле и переместить предыдущую фигуру на другую позицию, а у этой фигкрк обнулить все координаты

	}
	return (0);
}

void		solution_help(t_tetriminos tetriminos[27])
{
	unsigned short map[17];
	unsigned short	size_map;

	size_map = 2;
	ft_bzero(map, 17*sizeof(unsigned short));
	while ((solution(tetriminos, size_map, map, 0)) == 0)
	{
		ft_bzero(map, 17*sizeof(unsigned short));
		size_map++;
	}
	print
}
