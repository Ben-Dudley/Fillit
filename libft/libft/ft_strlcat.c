/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:12:30 by jgoyette          #+#    #+#             */
/*   Updated: 2018/11/29 09:33:03 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_i;
	size_t	src_i;
	size_t	len;

	src_i = 0;
	dst_i = ft_strlen(dst);
	len = ft_strlen(src);
	len += (size <= dst_i) ? size : dst_i;
	while (src[src_i] && (size_t)(dst_i + 1) < size)
	{
		dst[dst_i] = src[src_i];
		dst_i += 1;
		src_i += 1;
	}
	dst[dst_i] = '\0';
	return (len);
}
