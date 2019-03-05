/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:08:17 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/02 22:14:46 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# define BUFF_SIZE 21

struct	s_tetriminos
{
	char letter;
	unsigned short value;
	unsigned short weight;
	unsigned short height;
	unsigned short x;
	unsigned short y;
} t_tetriminos;

t_tetriminos     init_tetriminos(const char *str, char letter);

#endif
