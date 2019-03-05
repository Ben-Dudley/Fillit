/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:20:14 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/05 19:13:50 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

//Функция чекающая можем мы вставить фигуру или нет
int		check_tetrimino()
{
	return (1);
}

int	solution(t_tetriminos tetriminos[27], unsigned short size_map, unsigned short map[17])
{
	static int number = 0;
	if (tetriminos->letter == '\0')
		return (1);
	if (tetriminos->x + tetriminos->width >= size_map)
		tetriminos->y += 1;	
	if (tetriminos->y + tetriminos->height > size_map)
		return (0);	
	//В зависимости от текущего размера карты проверить сможем ли мы поставить фигуру
	if (check_tetrimino())
	{
		//1, тогда перейти к следующей фигуре
		//записать в мап найденную фигуру
		solution(tetriminos + 1, size_map, map);
		return (1);
	}
	else
	{
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
//определяющий минимальный размер карты
	while ((solution(tetriminos, size_map, map)) == 0)
	{
		ft_bzero(map, 17*sizeof(unsigned short));
		size_map++;
	}
	printf("READY!");
}
