#include "fillit.h"

int	main(int ac, char **av)
{
	t_tetriminos	tetriminos[MAX_TETRIMINOS + 1];
	int		fd;
	int		num_tetriminos;
	int		size;

	if (ac != 2)
		return (display_error_and_exit("error or smth else (?)"));
	if ((fd = open(av[1], O_RDONLY) == -1))
		return (display_error_and_exit("error"));
	if ((num_tetriminos = read_tetriminos(tetriminos, fd)) == 0)
		return (display_error_and_exit("error"));
	size = find_smallest_square(tetriminos, num_tetriminos);
	display_solution(tetriminos, num_tetriminos, size);
	//close(fd); ?
	return (0);
}
