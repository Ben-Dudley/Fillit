/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:39:05 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:41:58 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	size_t	start;
	size_t	end;

	result = NULL;
	if (s)
	{
		start = 0;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start += 1;
		end = ft_strlen(s);
		if (start == end)
			result = ft_strnew((size_t)0);
		else
			end -= 1;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end -= 1;
		result = ft_strsub(s, start, (size_t)(end - start + 1));
	}
	return (result);
}
