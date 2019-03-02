/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:08:17 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/02 18:14:12 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include "libft/libft.h"

struct	s_tetrimino
{
	char letter;
	unsigned short value;
	unsigned short weight;
	unsigned short height;
	unsigned short x;
	unsigned short y;
} t_tetrimino;
#endif
