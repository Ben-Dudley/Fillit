/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:06:50 by jgoyette          #+#    #+#             */
/*   Updated: 2019/03/09 20:38:28 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	display_error_and_exit(const char *error_msg)
{
	ft_putstr(error_msg);
	return (1);
}

int	main(int ac, char **av)
{
	t_tetris			tetris[MAX_TETRIS + 1];
	int					fd;
	int					num_tetris;
	int					size;

	if (ac != 2)
		return (display_error_and_exit("usage: ./fillit [filename]\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (display_error_and_exit("error\n"));
	if ((num_tetris = read_tetris(tetris, fd)) == 0)
		return (display_error_and_exit("error\n"));
	size = find_smallest_square(tetris, num_tetris);
	print(tetris, size, num_tetris);
	return (0);
}
