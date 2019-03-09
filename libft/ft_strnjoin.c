/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:28:05 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/11 14:28:09 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t	len;
	char	*result;

	result = NULL;
	if (s1 && s2)
	{
		len = ft_strlen((char *)s1) + n + 1;
		result = ft_strnew(len);
		if (result)
		{
			ft_strcpy(result, s1);
			ft_strncat(result, s2, n);
		}
	}
	return (result);
}
