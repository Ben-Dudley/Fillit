/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:44:15 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:44:17 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	ft_bzero((void *)dst, len);
	len = (len > ft_strlen(src)) ? ft_strlen(src) : len;
	dst = (char *)ft_memcpy((void *)dst, (const void *)src, len);
	return (dst);
}
