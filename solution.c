/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:20:14 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/05 22:11:01 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

//Функция чекающая можем мы вставить фигуру или нет
int		check_tetrimino(t_tetriminos tetrimino, unsigned short size_map, unsigned short map[17])
{
	unsigned short row;

	row = 0;
	while (tetrimino.x + tetrimino.width > size_map)
	{
		tetrimino.y += 1;	
		if (tetrimino.y + tetrimino.height > size_map)
			return (0);
	}
	while (row < 4)
	{
		while (((tetrimino.value << 4*row)*(tetrimino.value >> (3 - row) * 4) >> tetrimino.x) & map[tetrimino.y + row])
		{
			tetrimino.x++;
			if (tetrimino.x + tetrimino.width > size_map)
				tetrimino.y += 1;	
			if (tetrimino.y + tetrimino.height > size_map)
				return (0);
		}
		row++;
	}
	return (1);
}

int	solution(t_tetriminos tetriminos[27], unsigned short size_map, unsigned short map[17], unsigned short number)
{
	if (tetriminos->letter == '\0')
		return (1);
	//В зависимости от текущего размера карты проверить сможем ли мы поставить фигуру
	//map[0]= 32768;
	if (check_tetrimino(tetriminos[number], size_map, map))
	{
	printf("READY!");
		//1, тогда перейти к следующей фигуре
		//записать в мап найденную фигуру
//		solution(tetriminos, size_map, &(*map), number + 1);
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
	/*int i;
	i = -1;
	while (++i < 18)
		printf("map[%d] =%d\n",i, map[i]);*/
//определяющий минимальный размер карты
	while ((solution(tetriminos, size_map, map, 0)) == 0)
	{
		ft_bzero(map, 17*sizeof(unsigned short));
		size_map++;
	}
}
