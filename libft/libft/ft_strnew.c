/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:43:32 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:43:34 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	if (size == (size_t)-1)
		return (NULL);
	else
		return ((char *)ft_memalloc(sizeof(char) * (size_t)(size + 1)));
}
