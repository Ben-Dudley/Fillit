#include "fillit.h"
#include <stdio.h>

int	display_error_and_exit(const char *error_msg)
{
	printf(error_msg);
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
	{
		printf("fd: %d\n", fd);
		return (display_error_and_exit("error\n"));}
	if ((num_tetriminos = read_tetriminos(tetriminos, fd)) == 0) {//||
				//((size = find_smallest_square(tetriminos, num_tetriminos) == 0)
				printf("calling read_tetriminos()\n");
				 return (display_error_and_exit("error\n"));}
	//display_solution(tetriminos, num_tetriminos, size);
	close(fd);
	return (0);
}
