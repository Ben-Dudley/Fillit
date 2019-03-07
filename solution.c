/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:20:14 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/07 22:11:43 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int		check_tetrimino(t_tetriminos tetrimino, unsigned short size_map, unsigned short map[17])
{
	short row;
	unsigned short tmp;

	row = -1;
	while (++row < 4)
	{
		while ((tetrimino.x + tetrimino.width) > size_map && (tetrimino.y + tetrimino.height) <= size_map)
		{
			tetrimino.y += 1;	
			tetrimino.x = 0;
		}
		if (tetrimino.y + tetrimino.height > size_map)
			return (0);
		tmp =(tetrimino.value << 4*row);
		tmp = tmp >> (3 - row)*4;
		tmp = (tmp << (3 - row)*4) >> tetrimino.x;
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
		tmp = tmp >> 12;
		tmp = (tmp << 12) >> tetrimino.x;
		map[tetrimino.y + row] = map[tetrimino.y + row] + tmp;
		printf("put_shape: map = %d\n", map[tetrimino.y + row]);
	}
}

void	delete_shape(t_tetriminos tetrimino, unsigned short map[17])
{
	short row;
	short num;
	unsigned short tmp;

	row = -1;
	while (++row < 4)
	{
		tmp =(tetrimino.value << 4*row);
		tmp = tmp >> (3 - row)*4;
		tmp = (tmp << (3 - row)*4) >> tetrimino.x;
		map[tetrimino.y + row] = map[tetrimino.y + row] - tmp;
		printf("delete_shape: map = %d\n", map[tetrimino.y + row]);
	}
}

int	solution(t_tetriminos tetriminos[27], unsigned short size_map, unsigned short map[17], int  number)
{
	printf("Start! %d\n", size_map);
	if (tetriminos[number].letter == '\0')
		return (1);
	if (check_tetrimino(tetriminos[number], size_map, map))
	{
		put_shape(tetriminos[number], map);
		if (solution(tetriminos, size_map, map, number + 1))
			return (1);
	}
	else
	{
		tetriminos[number].x = 0;
		tetriminos[number].y = 0;
		if (number - 1 >= 0)
		{
			delete_shape(tetriminos[number -1], map);
			tetriminos[number - 1].x++;
			solution(tetriminos, size_map, map, number - 1);
		}
		else
			return (0);
	}
	return(0);
}

unsigned short		find_smallest_square(t_tetriminos tetriminos[27], int number)
{
	unsigned short map[17];
	unsigned short	size_map;

	size_map = 2;
	while (size_map*size_map < number*4)
		size_map++;
	ft_bzero(map, 17*sizeof(unsigned short));
	while ((solution(tetriminos, size_map, map, 0)) == 0)
	{
		printf("While\n");
		ft_bzero(map, 17*sizeof(unsigned short));
		size_map++;
	}
	print(tetriminos, size_map, number);
	return (size_map);
}
