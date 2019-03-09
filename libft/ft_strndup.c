/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:37:51 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:37:54 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	dup = (char *)ft_memalloc(sizeof(char) * (size_t)(n + 1));
	if (dup)
		dup = ft_strncpy(dup, s, n);
	return (dup);
}
