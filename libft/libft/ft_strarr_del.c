/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:52:14 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/09 18:52:16 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarr_del(char **tab, size_t tab_size)
{
	char	**tmp_tab;
	size_t	i;

	tmp_tab = tab;
	i = 0;
	while (i < tab_size)
	{
		if (tmp_tab[i])
			ft_strdel(&tmp_tab[i]);
		i += 1;
	}
	free(tab);
}
