/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:49:54 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:49:56 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int tmp_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp_n = (unsigned int)-n;
	}
	else
		tmp_n = (unsigned int)n;
	if (tmp_n >= 10)
		ft_putnbr_fd(tmp_n / 10, fd);
	ft_putchar_fd((char)(tmp_n % 10 + 48), fd);
}
