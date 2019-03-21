/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:12:07 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:43:18 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result_ptr;

	result_ptr = NULL;
	while (*s)
	{
		if (*s == c)
			result_ptr = (char *)s;
		s += 1;
	}
	if (c == '\0')
		return ((char *)s);
	return (result_ptr);
}
