#include "fillit.h"

int	read_tetrimino(t_tetrimino *tetriminos, int fd)
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
		if (is_tetrimino_valid(buff))
			tetriminos[count] = save_tetrimino(buff, letter + count);
		else
			return (0);
		count += 1;
	}
	if (nbytes == 0)
		return (count);
	else
		return (0);
}
