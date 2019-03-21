/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:58:25 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/12 20:40:33 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 21
# define MAX_TETRIS 26
# define MAX_SIZE_MAP 16

typedef struct s_tetris	t_tetris;

struct					s_tetris {
	char			letter;
	unsigned short	value;
	unsigned short	width;
	unsigned short	height;
	unsigned short	x;
	unsigned short	y;
	t_tetris		*last;
};

int						read_tetris(t_tetris *tetris, int fd);
t_tetris				init_tetris(const char *str, char letter,
								t_tetris *tetris, int count);
unsigned short			find_smallest_square(t_tetris *tetris,
								int tetris_count);
void					print(t_tetris *tetris, unsigned short size_map,
								int tetris_count);

#endif
