/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:45:19 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:47:18 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;
	unsigned int	len;

	ptr = NULL;
	i = 0;
	if (s && *s && f)
	{
		len = sizeof(char) * (ft_strlen((char *)s) + 1);
		ptr = (char *)ft_memalloc((size_t)len);
		if (ptr)
		{
			while (s[i])
			{
				ptr[i] = f(i, (char)s[i]);
				i += 1;
			}
		}
	}
	return (ptr);
}
