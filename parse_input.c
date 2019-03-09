/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:16:06 by jgoyette          #+#    #+#             */
/*   Updated: 2019/03/09 20:26:20 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	is_block_valid(const char *buff, int cell)
{
	int	connections;

	connections = 0;
	if (cell > 4 && buff[cell - 5] == '#')
		connections += 1;
	if (cell < 15 && buff[cell + 5] == '#')
		connections += 1;
	if (cell % 5 > 0 && buff[cell - 1] == '#')
		connections += 1;
	if (cell % 5 < 4 && buff[cell + 1] == '#')
		connections += 1;
	return (connections == 6 || connections == 8);
}

int	is_tetris_valid(const char *buff, int len)
{
	int i;
	int nblocks;

	i = 0;
	nblocks = 0;
	while (i < len - 1)
	{
		if (i % 5 != 4)
		{
			if (buff[i] == '#')
			{
				nblocks += 1;
				if (nblocks > 4 || !is_block_valid(buff, i))
					return (0);
			}
			else if (buff[i] != '.')
				return (0);
		}
		else if (buff[i] != '\n')
			return (0);
		i += 1;
	}
	if ((len == BUFF_SIZE && buff[i] != '\n') || nblocks < 4)
		return (0);
	return (1);
}

int	read_tetris(t_tetris *tetris, int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	letter;
	int		count;
	int		nbytes;
	int		found_eof;

	count = 0;
	letter = 'A';
	found_eof = 0;
	ft_bzero(tetris, sizeof(t_tetris) * MAX_TETRIS + 1);
	while ((nbytes = read(fd, buff, BUFF_SIZE)) >= BUFF_SIZE - 1)
	{
		buff[nbytes] = '\0';
		if (nbytes == 20)
			found_eof = 1;
		if (count <= 25 && is_tetris_valid(buff, nbytes))
			tetris[count] = init_tetris(buff, letter + count);
		else
			break ;
		count += 1;
	}
	close(fd);
	if (nbytes == 0 && found_eof)
		return (count);
	return (0);
}
