/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:22:56 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/05 22:11:03 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main()
{
	t_tetriminos	tetriminos[27];

	tetriminos[0].letter = 'A';
	tetriminos[0].value = 52224;
	tetriminos[0].width = 2;
	tetriminos[0].height = 2;
	tetriminos[0].x = 0;
	tetriminos[0].y = 0;
//	tetriminos[1].letter = 'B';
//	tetriminos[1].value = 52224;
//	tetriminos[1].width = 2;
//	tetriminos[1].height = 2;
//	tetriminos[1].x = 0;
//	tetriminos[1].y = 0;
	tetriminos[1].letter = '\0';
	solution_help(tetriminos);
	return (0);
}
