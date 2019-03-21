/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:44:44 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:47:48 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				ptr[i] = f((char)s[i]);
				i += 1;
			}
		}
	}
	return (ptr);
}
