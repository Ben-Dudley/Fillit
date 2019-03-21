/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:28:29 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/11 14:28:31 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *src, size_t size)
{
	void	*dup;

	dup = ft_memalloc(size);
	if (dup)
		dup = ft_memcpy(dup, src, size);
	return (dup);
}
