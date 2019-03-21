/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:28:58 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/11 14:28:59 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	if (alst && *alst && del)
	{
		current = *alst;
		while (current)
		{
			next = current->next;
			ft_lstdelone(&current, del);
			current = next;
		}
		*alst = NULL;
	}
}
