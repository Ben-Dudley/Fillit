#include "fillit.h"

int	is_block_valid(const char *buff, int cell)
{
	if (cell > 4 && buff[cell - 5] == '#' ||
		cell < 15 && buff[cell + 5] == '#' ||
		cell % 5 > 0 && buff[cell - 1] == '#' ||
		cell % 5 < 4 && buff[cell + 1] == '#')
		return (1);
	return (0);
}

int	is_tetriminos_valid(const char *buff, int len)
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
	if (len == BUFF_SIZE && buff[i] != '\n')
		return (0);
	return (1);
}

int	read_tetriminos(t_tetriminos *tetriminos, int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	letter;
	int	count;
	int	nbytes;

	count = 0;
	letter = 'A';
	while ((nbytes = read(fd, buff, BUFF_SIZE)) >= BUFF_SIZE - 1)
	{
		buff[nbytes] = '\0';
		if (count <= 25 && is_tetriminos_valid(buff, nbytes))
			tetriminos[count] = init_tetriminos(buff, letter + count);
		else
			return (0);
		count += 1;
	}
	if (nbytes == 0)
		return (count);
	else
		return (0);
}
