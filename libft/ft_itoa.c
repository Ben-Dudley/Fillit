/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:52:30 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:54:04 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_n_size(int n)
{
	size_t		size;

	size = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		size += 1;
	}
	if (n < 0)
		size += 1;
	return (size);
}

char			*ft_itoa(int n)
{
	char	*result;
	size_t	size;

	size = get_n_size(n);
	result = ft_strnew(size);
	if (result)
	{
		if (n < 0)
			result[0] = '-';
		while (n >= 10 || n <= -10)
		{
			result[size - 1] = (n < 0) ? (char)(-(n % 10) + 48) :\
										(char)(n % 10 + 48);
			n /= 10;
			size -= 1;
		}
		result[size - 1] = (n < 0) ? (char)(-n + 48) : (char)(n + 48);
	}
	return (result);
}
