/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:16:06 by jgoyette          #+#    #+#             */
/*   Updated: 2019/03/10 16:50:35 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_block_connections(const char *buff, int cell)
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
	return (connections);
}

int	is_tetris_valid(const char *buff, int len)
{
	int i;
	int nblocks;
	int connections;

	i = 0;
	nblocks = 0;
	connections = 0;
	while (i < len)
	{
		if (i % 5 != 4 && i < len - 1)
		{
			if (buff[i] == '#')
			{
				nblocks += 1;
				connections += get_block_connections(buff, i);
			}
			else if (buff[i] != '.')
				return (0);
		}
		else if (buff[i] != '\n' && buff[i] != '\0')
			return (0);
		i += 1;
	}
	return (nblocks == 4 && (connections == 6 || connections == 8));
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
		if (nbytes == BUFF_SIZE - 1)
			found_eof = 1;
		if (count < MAX_TETRIS && is_tetris_valid(buff, nbytes))
			tetris[count] = init_tetris(buff, letter + count, tetris, count);
		else
			break ;
		count += 1;
	}
	close(fd);
	if (nbytes == 0 && found_eof)
		return (count);
	return (0);
}
