#include "fillit.h"
#include <stdio.h>

int	display_error_and_exit(const char *error_msg)
{
	printf("%s", error_msg);
	return (1);
}

int	main(int ac, char **av)
{
	t_tetriminos	tetriminos[MAX_TETRIMINOS + 1];
	int		fd;
	int		num_tetriminos;
	int		size;

	if (ac != 2)
		return (display_error_and_exit("usage: ./fillit [filename]\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (display_error_and_exit("error\n"));
	if ((num_tetriminos = read_tetriminos(tetriminos, fd)) == 0)
		return (display_error_and_exit("error\n"));
	size = find_smallest_square(tetriminos, num_tetriminos);
	printf("solution map size: %d\n", size);
	print(tetriminos, size, num_tetriminos);
	//display_solution(tetriminos, num_tetriminos, size);`
	return (0);
}
